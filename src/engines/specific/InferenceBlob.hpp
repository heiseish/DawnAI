#pragma once

#ifndef DAWN_INFERENCE_BLOB
#define DAWN_INFERENCE_BLOB

#include <unordered_map>
#include <vector>
#include <string>

#include <boost/any.hpp>

namespace dawn {

template <typename T>
using InferenceInput = std::unordered_map<std::string, std::vector<T>>;

template <typename T>
using InferenceOutput = std::unordered_map<std::string, std::vector<T>>;

using InferenceResource = std::unordered_map<std::string, boost::any>;

}

#endif