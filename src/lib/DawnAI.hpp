#pragma once

#ifndef DAWN_AI
#define DAWN_AI

#include <iostream>
#include <string>
#include <memory>

#include <grpc++/grpc++.h>

#include "protos/image_recognition_service.grpc.pb.h"
#include "protos/converse_service.grpc.pb.h"

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
	// Converse
	using ConverseServiceGRPC::ConverseService;
	using ConverseServiceGRPC::ConversationInput;
	using ConverseServiceGRPC::ConversationResponse;
	using ConverseServiceGRPC::ConversationResponse_State;
	// Image
	using ImageRecognitionServiceRPC::ImageRecognitionService;
	using ImageRecognitionServiceRPC::ImageRequest;
	using ImageRecognitionServiceRPC::ImageResponse;
	using ImageRecognitionServiceRPC::ImageResponse_State;
	// Logic and data behind the server's behavior.
	class ConverseServiceImpl final : public ConverseService::Service {
	private:
		std::unique_ptr<dawn::TextGenerator> textGenerator;
	public:
		ConverseServiceImpl() {
			textGenerator = std::make_unique<TextGenerator>();
		}
		Status RespondToText(ServerContext* context, const ConversationInput* request,
			ConversationResponse* reply) override {
			if (!textGenerator) {
				reply->set_state(ConversationResponse_State::ConversationResponse_State_MODEL_ERR);
				return Status::OK;
			}
			reply->set_state(ConversationResponse_State::ConversationResponse_State_SUCCESS);
			reply->set_text(textGenerator->generateReply(request->text()));
			return Status::OK;
		}
	};

	class ImageRecognitionServiceImpl final : public ImageRecognitionService::Service {
	private:
		std::unique_ptr<dawn::ImageInference> imageInferencer;
	public:
		ImageRecognitionServiceImpl() {
			imageInferencer = std::make_unique<ImageInference>();
		}
		Status RecognizeImage(ServerContext* context, const ImageRequest* request,
			ImageResponse* reply) override {
			if (!imageInferencer) {
				reply->set_state(ImageResponse_State::ImageResponse_State_MODEL_ERR);
				return Status::OK;
			}
			reply->set_state(ImageResponse_State::ImageResponse_State_SUCCESS);
			auto result = imageInferencer->classifyBase64Image(request->image());
			reply->set_text(std::get<0>(result)); // extract the prediction
			return Status::OK;
		}
	};
	class DawnAI {
	private:
		std::shared_ptr<spdlog::logger> mainLogger;
		ConverseServiceImpl converse_service;
		ImageRecognitionServiceImpl image_recognition_service;
		std::unique_ptr<Server> server;
	public:
		DawnAI();
		void listen(std::string);
	};
}


#endif