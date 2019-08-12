#pragma once

#ifndef GENERATE_REPLY_H
#define GENERATE_REPLY_H

#include <torch/script.h>
#include <torch/torch.h>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "KeyWordDetector.hpp"
#include "src/utils/StringUtils.hpp"
#include "TorchDawn.hpp"

#include <json.hpp>

#include "src/utils/Logger.hpp"

namespace dawn {

class Seq2Seq {
private:
	// std::shared_ptr<torch::jit::script::Module> module;
	std::unique_ptr<TorchDawn> module;
	std::shared_ptr<dawn::KeyWordDetector> profanityDetector;
	std::shared_ptr<dawn::StringUtils> currentStringUtils;
	std::shared_ptr<Logger> logger;
	bool ready = true;
public:
	
	Seq2Seq(const std::string& path="src/model/seq2seq/chat.pth", 
		const std::string& profanityCollection="src/model/seq2seq/profanity.json");
	static const int MAX_LENGTH=StringUtils::MAX_LENGTH;
	bool generateReply(const std::string& s, std::string& output);
};
	
}
#endif
