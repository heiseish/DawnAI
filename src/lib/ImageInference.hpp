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

#include "utils/OpenCvUtils.hpp"

#include <websocketpp/base64/base64.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace dawn {
	class ImageInference {
	private:
		std::vector<std::string> labels;
		std::shared_ptr<torch::jit::script::Module> model;
		std::shared_ptr<spdlog::logger> imageInferenceLogger;
		std::shared_ptr<torch::jit::script::Module> readModel(std::string);
		std::vector<float> forward(std::vector<cv::Mat>,
		  std::shared_ptr<torch::jit::script::Module>);
		std::tuple<std::string, std::string> postprocess(std::vector<float>,
		  std::vector<std::string>);
		torch::Tensor __convert_images_to_tensor(std::vector<cv::Mat>);
		torch::Tensor __predict(torch::Tensor);
		std::vector<float> __softmax(std::vector<float>);
		std::vector<float> __get_outputs(torch::Tensor);
	public:
		static const int imageHeight = 224;
	  	static const int imageWidth = 224;
	  	std::vector<double> mean;
		std::vector<double> std;

		ImageInference(const char* labelPath="src/model/labels.txt", 
			const char* modelPath="src/model/resnet_model.pth");
		std::tuple<std::string, std::string> infer(cv::Mat);
		std::tuple<std::string, std::string> classifyLocalImage(const char*);
		std::tuple<std::string, std::string> classifyBase64Image(std::string);
	};
}



#endif
