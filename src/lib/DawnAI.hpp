#pragma once

#ifndef DAWN_AI
#define DAWN_AI

#include <iostream>
#include <string>
#include <memory>

#include <grpc++/grpc++.h>

#include "protos/text_generator_service.grpc.pb.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "TextGenerator.hpp"
#include "ImageInference.hpp"




namespace dawn {

	using grpc::Server;
	using grpc::ServerBuilder;
	using grpc::ServerContext;
	using grpc::Status;
	using TextGeneratorGRPC::TextResponseService;
	using TextGeneratorGRPC::Sentence;
	using TextGeneratorGRPC::Response;
	// Logic and data behind the server's behavior.
	class TextGeneratorServiceImpl final : public TextResponseService::Service {
		Status RespondToText(ServerContext* context, const Sentence* request,
			Response* reply) override {
			std::string prefix("Hello ");
			reply->set_reply(prefix + request->greeting());
			return Status::OK;
		}
	};
	class DawnAI {
	private:
		std::shared_ptr<dawn::TextGenerator> textGenerator;
		std::shared_ptr<dawn::ImageInference> imageInferencer;
		std::shared_ptr<spdlog::logger> mainLogger;
		TextGeneratorServiceImpl service;
	public:
		DawnAI();
		void listen(std::string);
	};
}


#endif