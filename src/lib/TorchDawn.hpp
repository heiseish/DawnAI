#pragma once

#ifndef DAWNTORCH_H
#define DAWNTORCH_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include <sys/stat.h>
#include <torch/script.h>
#include <torch/serialize/tensor.h>
#include <torch/serialize.h>
#include <torch/utils.h>
#include <ATen/core/ivalue.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace dawn {

class TorchDawn {
private:
	std::shared_ptr<torch::jit::script::Module> model;
	torch::NoGradGuard noGrad;	
	std::shared_ptr<spdlog::logger> TorchLogger;
public:
	TorchDawn(const std::string&, bool&);
	template <typename T>
	bool forward(torch::jit::Stack& input, std::vector<T>& output, const int& requiredOutputIdx=0);
	template <typename T>
	bool forward(torch::Tensor&, std::vector<T>&, const int& requiredOutputIdx=0);
};

template <typename T>
bool TorchDawn::forward(torch::jit::Stack& input, std::vector<T>& output, const int& requiredOutputIdx) {
	auto result  = model->forward(input);
	torch::Tensor model_output;
	if (requiredOutputIdx == 0) {
		model_output = result.toTensor();
	} else {
		model_output = result.toTuple()->elements()[requiredOutputIdx - 1].toTensor();
	}
	int ndim = model_output.ndimension();
	int64_t totalSize = 1LL;
	auto sizes = model_output.sizes();
	for (int i = 0; i < ndim; ++i) {
		if (totalSize > LLONG_MAX / sizes[i]) {
			return false;
		}
		totalSize *= sizes[i];
	}
	auto start = model_output.data<T>();
	output = std::vector<T>(start, start + totalSize);
	return true;
}

template <typename T>
bool TorchDawn::forward(torch::Tensor& input, std::vector<T>& output, const int& requiredOutputIdx) {
	auto result = model->forward({ input });
	torch::Tensor model_output;
	if (requiredOutputIdx == 0) {
		model_output = result.toTensor();
	} else {
		model_output = result.toTuple()->elements()[requiredOutputIdx - 1].toTensor();
	}
	int ndim = model_output.ndimension();
	int64_t totalSize = 1LL;
	auto sizes = model_output.sizes();
	for (int i = 0; i < ndim; ++i) {
		if (totalSize > LLONG_MAX / sizes[i]) {
			return false;
		}
		totalSize *= sizes[i];
	}
	auto start = model_output.data<T>();
	output = std::vector<T>(start, start + totalSize);
	return true;
}

}


#endif
