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



class TorchEngine : public InferenceEngine<c10::IValue, c10::IValue>  {
public:
    TorchEngine(int32_t id) : InferenceEngine(id) {}
    ~TorchEngine() {}
    bool Initialize(const InferenceResource&) override;
    bool Forward( InferenceOutput<c10::IValue>& ouput, const InferenceInput<c10::IValue>& input) const;
    
private:
    int _idx = 0;
    std::shared_ptr<torch::jit::script::Module> model;
	torch::NoGradGuard noGrad;

};

}

#endif