// Inspiration: https://github.com/Wizaron/pytorch-cpp-inference
#include "ImageClassifier.hpp"

#include <iostream>
#include <vector>
#include <tuple>
#include <chrono>
#include <fstream>
#include <random>
#include <string>
#include <memory>

#include <torch/script.h>
#include <torch/serialize/tensor.h>
#include <torch/serialize.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <websocketpp/base64/base64.hpp>

#include "src/utils/Logger.hpp"
#include "src/utils/Image.hpp"

#include "src/engines/specific/InferenceBlob.hpp"
#include "src/engines/specific/TorchEngine.hpp"
#include "src/engines/specific/InferenceEngine.hpp"

namespace dawn {


bool ImageClassifier::Initialize(const std::string labelPath, const std::string modelPath) {
	std::string label;
	std::ifstream labelsfile (labelPath);
	if (labelsfile.is_open()) {
		while (getline(labelsfile, label)) {
			labels.push_back(label);
		}
		labelsfile.close();
	}
    InferenceResource resource;
    resource.emplace(INFERENCE_ENGINE_MODEL_PATH, modelPath);
	model = std::make_unique<TorchEngine>(169);
    if (!model->Initialize(resource)) {
        DAWN_ERROR << "Failed to load torch engine for image classifier\n";
        return false;
    } 
    ready = true;
    DAWN_INFO << "Image classifier is loadded up successfully!\n";
    return true;
}

// Convert a vector of images to torch Tensor
bool ImageClassifier::__convert_images_to_tensor(std::vector<cv::Mat> images, torch::Tensor& output) const {
	int n_images = images.size();
	int n_channels = images[0].channels();
	int height = images[0].rows;
	int width = images[0].cols;
	int image_type = images[0].type();
  	// Image Type must be one of CV_8U, CV_32F, CV_64F
	assert((image_type % 8 == 0) || ((image_type - 5) % 8 == 0) || ((image_type - 6) % 8 == 0));
	std::vector<int64_t> dims = {1, height, width, n_channels};
	std::vector<int64_t> permute_dims = {0, 3, 1, 2};
	std::vector<torch::Tensor> images_as_tensors;
	for (int i = 0; i != n_images; i++) {
		cv::Mat image = images[i].clone();
		torch::Tensor image_as_tensor;
		if (image_type % 8 == 0) {
			torch::TensorOptions options(torch::kUInt8);
			image_as_tensor = torch::from_blob(image.data, torch::IntList(dims), options).clone();
		} else if ((image_type - 5) % 8 == 0) {
			torch::TensorOptions options(torch::kFloat32);
			image_as_tensor = torch::from_blob(image.data, torch::IntList(dims), options).clone();
		} else if ((image_type - 6) % 8 == 0) {
			torch::TensorOptions options(torch::kFloat64);
			image_as_tensor = torch::from_blob(image.data, torch::IntList(dims), options).clone();
		}
		image_as_tensor = image_as_tensor.permute(torch::IntList(permute_dims));
		image_as_tensor = image_as_tensor.toType(torch::kFloat32);
		images_as_tensors.push_back(image_as_tensor);
	}
	output = torch::cat(images_as_tensors, 0);
	return true;
}


bool ImageClassifier::__softmax(const std::vector<float>& unnorm_probs, std::vector<float>& output) const {
	int n_classes = unnorm_probs.size();
	output.resize(n_classes);
  	// 1. Partition function
	float log_sum_of_exp_unnorm_probs = 0;
	for (auto& n : unnorm_probs) {
		log_sum_of_exp_unnorm_probs += std::exp(n);
	}
	log_sum_of_exp_unnorm_probs = std::log(log_sum_of_exp_unnorm_probs);
  	// 2. normalize
	for (int class_idx = 0; class_idx != n_classes; class_idx++) {
		output[class_idx] = std::exp(unnorm_probs[class_idx] - log_sum_of_exp_unnorm_probs);
	}
	return true;
}


// 2. Forward
bool ImageClassifier::forward(std::vector<cv::Mat> images, std::vector<float>& output) const {
	torch::Tensor tensor;
	if (!__convert_images_to_tensor(images, tensor)) {
		return false;
	}
    c10::IValue outputBlob;
    torch::jit::Stack inputBlob { tensor };
    // ------------------- Inference ------------------------
	if (!model->Forward(outputBlob, inputBlob)) {
        DAWN_ERROR << "Image classifier inference failed\n";
		return false;
	}
    // -------------------- get output tensor -----------------------
    auto outputTensor = outputBlob.toTensor();
    int ndim = outputTensor.ndimension();
    size_t totalSize = 1;
    auto sizes = outputTensor.sizes();
    for (int i = 0; i < ndim; ++i) {
        if (totalSize > LLONG_MAX / sizes[i]) {
            return false;
        }
        totalSize *= sizes[i];
    }
    auto start = outputTensor.data<float>();
    std::vector<float> unnorm_probs(start, start + totalSize);
	return __softmax(unnorm_probs, output);
}

// 3. Postprocess
std::tuple<std::string, std::string> ImageClassifier::postprocess(const std::vector<float> probs,
const std::vector<std::string>& labels) const {
  // 1. Get label and corresponding probability
	auto prob = std::max_element(probs.begin(), probs.end());
	auto label_idx = std::distance(probs.begin(), prob);
	auto label = labels[label_idx];
	float prob_float = *prob;
	return std::make_tuple(label, std::to_string(prob_float));
}


bool ImageClassifier::infer(cv::Mat image, std::string& output) const {
	if (image.empty()) {
		DAWN_ERROR << "Cannot read image!\n";
		return false;
	}
	std::string prob = "0.0";
	cv::Mat preprocessedImage;
	// Preprocess image
	if (!ImageUtil::Preprocess(preprocessedImage, image)) {
        DAWN_ERROR << "Image preprocess failed!\n";
		return false;
	}
	std::vector<float> probabilities;
	// Forward
	if (!forward({preprocessedImage, }, probabilities)) {
		return false;
	}
	// Postprocess
	tie(output, prob) = postprocess(probabilities, labels);
	return true;
}


bool ImageClassifier::ClassifyLocalImage(const std::string& imagePath,  std::string &output) const {
	cv::Mat image = cv::imread(imagePath, -1);
	std::string pred, prob;
	return infer(image, output);
}

bool ImageClassifier::ClassifyImage(const std::string& url, std::string& output) const {
	if (!ready) {
		DAWN_ERROR << "Image inference model not ready\n";
		return false;
	}
    DAWN_INFO << "Running image classification service!\n";
	cv::Mat image;
	if (!ImageUtil::Download(image, url.c_str())) {
		return false;
	}
	if (!infer(image, output)) {
        return false;
    }
    DAWN_INFO << "Image classification ran successfully!\n";
    return true;
}

}



