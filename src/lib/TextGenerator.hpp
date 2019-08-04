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
#include "src/utils/PytorchUtils.hpp"

#include <json.hpp>


#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace dawn {
	class TextGenerator {
	private:
		std::shared_ptr<torch::jit::script::Module> module;
		std::shared_ptr<dawn::KeyWordDetector> profanityDetector;
		std::shared_ptr<dawn::StringUtils> currentStringUtils;
		std::shared_ptr<spdlog::logger> textGeneratorInputLogger;
		std::shared_ptr<spdlog::logger> textGeneratorResponseLogger;
	public:
		TextGenerator(const char* path="src/model/chat.pth", 
			const char* profanityCollection="src/model/profanity.json");
		std::string generateReply(const std::string& s, const int MAX_LENGTH=dawn::StringUtils::MAX_LENGTH);
	};
	
}
#endif
