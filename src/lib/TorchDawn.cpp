#include "TorchDawn.hpp"

#include <memory>
#include <string>
#include <limits>
#include <vector>
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

TorchDawn::TorchDawn(const std::string& modelPath, bool& success) {	
	model = std::make_shared<torch::jit::script::Module>(torch::jit::load(modelPath));
	noGrad = torch::NoGradGuard();
	success = (model != nullptr);
}


}