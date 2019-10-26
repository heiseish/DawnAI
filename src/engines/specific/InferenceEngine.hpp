#pragma once

#ifndef DAWN_INFERENCE_ENGINE
#define DAWN_INFERENCE_ENGINE
#include "InferenceBlob.hpp"

namespace dawn {

#define INFERENCE_ENGINE_MODEL_PATH "model_path"

template <typename InputType, typename OutputType>
class InferenceEngine {
public:
    InferenceEngine(int32_t id): _id(id)  { }
    ~InferenceEngine() {}
    virtual bool Initialize(const InferenceResource&) = 0;
    virtual bool Forward(InferenceOutput<OutputType>& ouput, const InferenceInput<InputType>& input) const = 0;
protected:
    int32_t _id;
};

}

#endif