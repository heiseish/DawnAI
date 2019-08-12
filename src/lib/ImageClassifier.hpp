#pragma once

#ifndef INFER_H 
#define INFER_H

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

#include "src/utils/ImageUtils.hpp"
#include "TorchDawn.hpp"

#include <websocketpp/base64/base64.hpp>
#include "src/utils/Logger.hpp"

namespace dawn {
class ImageClassifier {
private:
	std::vector<std::string> labels;
	std::unique_ptr<TorchDawn> model;
	std::shared_ptr<Logger> logger;
	bool forward(std::vector<cv::Mat>, std::vector<float>&);
	std::tuple<std::string, std::string> postprocess(const std::vector<float>,
		const std::vector<std::string>&);
	bool __convert_images_to_tensor(std::vector<cv::Mat>, torch::Tensor&);
	bool __softmax(const std::vector<float>&, std::vector<float>&);
	bool infer(cv::Mat, std::string&);
	bool ready = true;
public:
	static const int imageHeight = 224;
	static const int imageWidth = 224;
	std::vector<double> mean;
	std::vector<double> std;

	ImageClassifier(const std::string labelPath="src/model/imageClassifier/labels.txt", 
		const std::string modelPath="src/model/imageClassifier/resnet_model.pth");
	
	bool classifyLocalImage(const std::string&, std::string&);
	bool classifyImage(const std::string&, std::string&);
};
}



#endif
