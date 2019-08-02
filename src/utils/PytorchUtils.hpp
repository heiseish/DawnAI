#pragma once

#ifndef PYTORCHUTILS_H 
#define PYTORCHUTILS_H

#include <memory>

#include <torch/script.h>
#include <torch/serialize/tensor.h>
#include <torch/serialize.h>

namespace dawn {
	std::shared_ptr<torch::jit::script::Module> readModel(std::string model_path);
}


#endif
