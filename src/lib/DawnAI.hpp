#pragma once

#ifndef DAWN_AI
#define DAWN_AI

#include <iostream>
#include <string>
#include <memory>

#include <crow.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "lib/TextGenerator.hpp"
#include "lib/ImageInference.hpp"

namespace dawn {
	class DawnAI {
	private:
		crow::SimpleApp app;
		std::shared_ptr<dawn::TextGenerator> textGenerator;
		std::shared_ptr<dawn::ImageInference> imageInferencer;
		std::shared_ptr<spdlog::logger> mainLogger;
	public:
		DawnAI();
		void listen(int);
	};
}


#endif