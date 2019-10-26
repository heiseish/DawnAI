#pragma once

#ifndef GENERATE_REPLY_H
#define GENERATE_REPLY_H

#include <torch/script.h>
#include <torch/torch.h>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include <json.hpp>

#include "src/utils/String.hpp"

#include "src/utils/Logger.hpp"
#include "src/engines/specific/InferenceEngine.hpp"
#include "src/engines/specific/TorchEngine.hpp"
namespace dawn {

class Seq2Seq {
private:
	std::unique_ptr<InferenceEngine<c10::IValue, c10::IValue>> _engine;
    std::unordered_map<std::string, int64_t> word2index;
	std::unordered_map<int64_t, std::string> index2word;
    static const int PAD_token = 0;  // Used for padding short sentences
	static const int SOS_token = 1;  // Start-of-sentence token
	static const int EOS_token = 2;  // End-of-sentence token
	static const int MIN_COUNTs = 3;  // Minimum word count threshold for trimming
	static const int MAX_LENGTH = 10;  // Maximum sentence length to consider
    bool indexesFromSentence(std::vector<int64_t>&, const std::string&);
	bool sentenceFromIndexes(std::string&, const std::vector<int64_t>&);
	bool ready = false;
public:
	Seq2Seq() {}
    bool Initialize(const std::string& path="src/model/seq2seq/chat.pth",
        const std::string& word2indexPath="src/model/seq2seq/word2index.json", 
		const std::string& index2wordPath="src/model/seq2seq/index2word.json");
	bool GenerateReply(const std::string& s, std::string& output);
};
	
}
#endif
