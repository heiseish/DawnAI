#pragma once

#ifndef TORCH_ENGINE
#define TORCH_ENGINE

#include "InferenceEngine.hpp"
#include "InferenceBlob.hpp"

#include <string>
#include <memory>
#include <vector>

#include <torch/script.h>
#include <torch/serialize/tensor.h>
#include <torch/serialize.h>
#include <torch/utils.h>


namespace dawn {



class TorchEngine : public InferenceEngine {
public:
    TorchEngine(int32_t id) : InferenceEngine(id) {}
    ~TorchEngine() {}
    bool Initialize(const InferenceResource&) override;
    bool Forward( InferenceOutput& ouput, const InferenceInput& input) const override;
    bool Forward( c10::IValue& ouput, const torch::jit::Stack& input) const;
    
private:
    int _idx = 0;
    // bool postProcess(InferenceOutput& ouput, const torch::Tensor model_output) const;
    std::shared_ptr<torch::jit::script::Module> model;
	torch::NoGradGuard noGrad;

};

}

#endif