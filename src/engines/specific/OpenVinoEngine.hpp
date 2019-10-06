#pragma once

#ifndef OPENVINO_ENGINE
#define TORCH_ENGINE

#include "InferenceEngine.hpp"


namespace dawn {

template <class T>
class OpenVinoEngine : public InferenceEngine<T> {
public:
    InferenceEngine();
    ~InferenceEngine();
    bool Initialize(const InferenceResource&);
    bool Forward(InferenceOutput<T>& ouput, const InferenceInput<T>& input);
private:

}

}

#endif