// Inspiration: https://github.com/Wizaron/pytorch-cpp-inference
#include "lib/ImageInference.hpp"

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

#include "utils/OpenCvUtils.hpp"

#include <websocketpp/base64/base64.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

const int dawn::ImageInference::imageHeight;
const int dawn::ImageInference::imageWidth;

dawn::ImageInference::ImageInference(const char* labelPath, const char* modelPath) {
	mean = {0.485, 0.456, 0.406};
	std = {0.229, 0.224, 0.225} ;
	imageInferenceLogger = spdlog::stdout_color_mt("Image Inference Logger");
	std::string label;
	std::ifstream labelsfile (labelPath);
	if (labelsfile.is_open()) {
		while (getline(labelsfile, label)) {
			labels.push_back(label);
		}
		labelsfile.close();
	}
	model = readModel(modelPath);
	if (model.get() == nullptr) {
		imageInferenceLogger->warn("Image classifier not loaded");
	} else {
		imageInferenceLogger->info("Image classifier loaded successfully");
	}
}

// Convert a vector of images to torch Tensor
torch::Tensor dawn::ImageInference::__convert_images_to_tensor(std::vector<cv::Mat> images) {
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
	torch::Tensor output_tensor = torch::cat(images_as_tensors, 0);
	return output_tensor;
}

// Predict
torch::Tensor dawn::ImageInference::__predict(torch::Tensor tensor) {
	std::vector<torch::jit::IValue> inputs;
	inputs.push_back(tensor);
  	// Execute the model and turn its output into a tensor.
	torch::Tensor output = model->forward(inputs).toTensor();
	return output;
}

// Softmax
std::vector<float> dawn::ImageInference::__softmax(std::vector<float> unnorm_probs) {
	int n_classes = unnorm_probs.size();
  	// 1. Partition function
	float log_sum_of_exp_unnorm_probs = 0;
	for (auto& n : unnorm_probs) {
		log_sum_of_exp_unnorm_probs += std::exp(n);
	}
	log_sum_of_exp_unnorm_probs = std::log(log_sum_of_exp_unnorm_probs);
  	// 2. normalize
	std::vector<float> probs(n_classes);
	for (int class_idx = 0; class_idx != n_classes; class_idx++) {
		probs[class_idx] = std::exp(unnorm_probs[class_idx] - log_sum_of_exp_unnorm_probs);
	}
	return probs;
}

// Convert output tensor to vector of floats
std::vector<float> dawn::ImageInference::__get_outputs(torch::Tensor output) {
	int ndim = output.ndimension();
	assert(ndim == 2);
	torch::IntList sizes = output.sizes();
	int n_samples = sizes[0];
	int n_classes = sizes[1];
	assert(n_samples == 1);
	std::vector<float> unnorm_probs(output.data<float>(),
	output.data<float>() + (n_samples * n_classes));
  	// Softmax
	std::vector<float> probs = __softmax(unnorm_probs);
	return probs;
}

// 1. Read model
std::shared_ptr<torch::jit::script::Module> dawn::ImageInference::readModel(std::string model_path) {
	return torch::jit::load(model_path);
}

// 2. Forward
std::vector<float> dawn::ImageInference::forward(std::vector<cv::Mat> images,
std::shared_ptr<torch::jit::script::Module> model) {
  	// 1. Convert OpenCV matrices to torch Tensor
	torch::Tensor tensor = __convert_images_to_tensor(images);
  	// 2. Predict
	torch::Tensor output = __predict(tensor);
  	// 3. Convert torch Tensor to vector of vector of floats
	std::vector<float> probs = __get_outputs(output);
	return probs;
}

// 3. Postprocess
std::tuple<std::string, std::string> dawn::ImageInference::postprocess(std::vector<float> probs,
std::vector<std::string> labels) {
  // 1. Get label and corresponding probability
	auto prob = std::max_element(probs.begin(), probs.end());
	auto label_idx = std::distance(probs.begin(), prob);
	auto label = labels[label_idx];
	float prob_float = *prob;
	return std::make_tuple(label, std::to_string(prob_float));
}


std::tuple<std::string, std::string> dawn::ImageInference::infer(cv::Mat image) {
	if (image.empty()) {
		imageInferenceLogger->warn("WARNING: Cannot read image!");
	}
	std::string pred = "";
	std::string prob = "0.0";
  	// Predict if image is not empty
	if (!image.empty()) {
	    // Preprocess image
		image = preprocess(image, imageHeight, imageWidth,mean, std);
	    // Forward
		std::vector<float> probs = forward({image, }, model);
	    // Postprocess
		tie(pred, prob) = postprocess(probs, labels);
	}
	imageInferenceLogger->info(pred);
	return std::make_tuple(pred, prob);
}


std::tuple<std::string, std::string> dawn::ImageInference::classifyLocalImage(const char* imagePath) {
	cv::Mat image = cv::imread(imagePath, -1);
	std::string pred, prob;
	return infer(image);
}

std::tuple<std::string, std::string> dawn::ImageInference::classifyBase64Image(std::string base64Image) {
      std::string decodedImage = websocketpp::base64_decode(base64Image);
      std::vector<uchar> imageData(decodedImage.begin(), decodedImage.end());
      cv::Mat image = cv::imdecode(imageData, cv::IMREAD_UNCHANGED);
      std::string pred, prob;
      return infer(image);
}


