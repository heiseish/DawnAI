#pragma once

#ifndef DAWN_INFERENCE_BLOB
#define DAWN_INFERENCE_BLOB

#include <unordered_map>
#include <vector>
#include <string>

#include <boost/any.hpp>

namespace dawn {


using InferenceInput = std::unordered_map<std::string, std::vector<float>>;

using InferenceOutput = std::unordered_map<std::string, std::vector<float>>;

using InferenceResource = std::unordered_map<std::string, boost::any>;

}

#endif