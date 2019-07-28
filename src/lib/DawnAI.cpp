#include "lib/DawnAI.hpp"

#include <iostream>
#include <string>
#include <memory>

#include <crow.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "lib/TextGenerator.hpp"
#include "lib/ImageInference.hpp"

dawn::DawnAI::DawnAI() {
	spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
	mainLogger = spdlog::stdout_color_mt("Main Logger");
	
	textGenerator = std::make_shared<dawn::TextGenerator>();
	imageInferencer = std::make_shared<dawn::ImageInference>();

	mainLogger->info("Server starting up!");
	

	CROW_ROUTE(app, "/converse")
	.methods("POST"_method)
	([&](const crow::request& req){
		auto x = crow::json::load(req.body);
		if (!x || x["text"])
			return crow::response(400);
		std::string input = x["text"].s();
		auto answer = textGenerator->generateReply(input);
        crow::json::wvalue resp;
        resp["answer"] = answer;
		return crow::response(resp);
	});


	CROW_ROUTE(app, "/image-recognizer")
	.methods("POST"_method)
	([&](const crow::request& req){
		auto x = crow::json::load(req.body);
		if (!x || !x["image"])
			return crow::response(400);
		std::string input = x["image"].s();
		auto [answer, prob] = imageInferencer->classifyBase64Image(input);
		crow::json::wvalue resp;
		resp["answer"] = answer;
		resp["prob"] = prob;
		return crow::response(resp);
	});
}

void dawn::DawnAI::listen(int PORT) {
	app.loglevel(crow::LogLevel::Warning);
	app.port(PORT).multithreaded().run();  
}