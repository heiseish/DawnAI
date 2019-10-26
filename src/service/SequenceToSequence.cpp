#include "SequenceToSequence.hpp"

#include <torch/script.h>
#include <torch/torch.h>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <regex>

#include "src/utils/String.hpp"
#include <json.hpp>
#include <boost/any.hpp>
#include <fmt/format.h>

#include "src/engines/specific/InferenceBlob.hpp"
#include "src/engines/specific/TorchEngine.hpp"
#include "src/engines/specific/InferenceEngine.hpp"
#include "src/utils/Logger.hpp"

namespace dawn {

const int Seq2Seq::PAD_token;
const int Seq2Seq::SOS_token;
const int Seq2Seq::EOS_token;
const int Seq2Seq::MIN_COUNTs;
const int Seq2Seq::MAX_LENGTH;

bool Seq2Seq::Initialize(const std::string& path, const std::string& word2indexPath, 
	const std::string& index2wordPath) {
    InferenceResource resource;
    resource.emplace(INFERENCE_ENGINE_MODEL_PATH, path);
	_engine = std::make_unique<TorchEngine>(69);
    
    if (!_engine->Initialize(resource)) {
        DAWN_ERROR << "Failed to load torch engine\n";
        ready = false;
    }
    ready = true;
    std::ifstream ifsw2i(word2indexPath, std::ifstream::binary);
	auto f = nlohmann::json::parse(ifsw2i);
	for (auto& item : f.items()) {
		auto& key = item.key();
		auto& value = item.value();
		word2index[key] = value;
	}
	std::ifstream ifsi2w(index2wordPath, std::ifstream::binary);
	auto s = nlohmann::json::parse(ifsi2w);
	for (auto& item : s.items()) {
		auto& key = item.key();
		auto& value = item.value();
		index2word[std::stoll(key)] = value;
	}
    DAWN_INFO << "Sequence2Sequence service loaded successfully!\n";
    return true;
}


bool Seq2Seq::indexesFromSentence(std::vector<int64_t>& output, const std::string& sentence) {
	const int EOS_token = 2;
	std::regex rg("\\s+");

	std::vector<std::string> out(
	std::sregex_token_iterator(sentence.begin(), sentence.end(), rg, -1),
	std::sregex_token_iterator()
	);
	output.resize(out.size());
	for(int i = 0; i < (int) out.size(); ++i) {
        if (!word2index.count(out[i])) {
            DAWN_ERROR << "Word not in dictionary\n";
            return false;
        }
		output[i] = word2index.at(out[i]);
	}
	output.emplace_back(EOS_token);
    return true;
}

bool Seq2Seq::sentenceFromIndexes(std::string& output, const std::vector<int64_t>& indexes) {
	output.clear();
	for (auto &val : indexes) {
		if (val == EOS_token) break; //EOS
        if (!index2word.count(val)) {
            DAWN_ERROR << "Index not present in dictionary\n";
            return false;
        }
		output += index2word[val];
		output += ' ';
	}
	return true;
}

/**
 *  @brief generate reply using sequence to sequence torch engine
 */
bool Seq2Seq::GenerateReply(const std::string& input, std::string& output) {
    DAWN_INFO << "Running Sequence to Sequence\n";
	if (!ready) {
        DAWN_ERROR << "Sequence to sequence service is not ready.\n";
		return false;
	}
    // ------------------------------------ Preprocess --------------------------------
	std::string normalizedString;
    StringUtil::NormalizeString(normalizedString, input);
	at::TensorOptions options(at::ScalarType::Long);
    std::vector<int64_t> indexes;
    if (!indexesFromSentence(indexes, normalizedString)) {
        return false;
    }
	// convert temp into length x 1 Tensor
    int64_t length = static_cast<int64_t>(indexes.size());
	auto inputSequence = torch::from_blob(indexes.data(), { length, 1 }, options);
    std::vector<int64_t> lengthVector { length };
	auto lengthTensor = torch::from_blob(lengthVector.data(), { 1 } , options);
	// ----------------------------- Create inference input ---------------------------
    InferenceOutput<c10::IValue> outputBlob;
	torch::jit::Stack modelInputValue { inputSequence, lengthTensor, MAX_LENGTH};
    InferenceInput<c10::IValue> modelInput;
    modelInput.emplace("1", std::move(modelInputValue));
	// ----------------------------------- Forward ----------------------------------
	if (!_engine->Forward(outputBlob, modelInput)) {
        DAWN_ERROR << "Torch engine inference failed";
		return false;
	}
    // ----------------------------------- Post process -----------------------------------
    auto outputTensor = outputBlob.begin()->second[0].toTuple()->elements()[0].toTensor();
    int ndim = outputTensor.ndimension();
    size_t totalSize = 1;
    auto sizes = outputTensor.sizes();
    for (int i = 0; i < ndim; ++i) {
        if (totalSize > LLONG_MAX / sizes[i]) {
            return false;
        }
        totalSize *= sizes[i];
    }
    auto start = outputTensor.data<int64_t>();
    std::vector<int64_t> modelOutput(start, start + totalSize);
    // -------------------------------------------------------------------------------
    
	if (!sentenceFromIndexes(output, modelOutput)) {
        DAWN_ERROR << "Failed to parse index to string\n";
        return false;
    }
    DAWN_INFO << "Sequence to sequence ran successfully\n";
	return  true;
}

}
