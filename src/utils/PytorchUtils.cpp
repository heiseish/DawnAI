#include "PytorchUtils.hpp"
#include <memory>

#include <torch/script.h>
#include <torch/serialize/tensor.h>
#include <torch/serialize.h>

std::shared_ptr<torch::jit::script::Module> dawn::readModel(std::string model_path) {
	return std::make_shared<torch::jit::script::Module>(torch::jit::load(model_path));
}