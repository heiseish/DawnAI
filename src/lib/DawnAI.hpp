#pragma once

#ifndef DAWN_AI
#define DAWN_AI

#include <iostream>
#include <string>
#include <memory>

#include <grpc++/grpc++.h>

#include "protos/image_classification_service.grpc.pb.h"
#include "protos/seq2seq_service.grpc.pb.h"

#include "src/utils/Logger.hpp"

#include "src/service/SequenceToSequence.hpp"
#include "src/service/ImageClassifier.hpp"




namespace dawn {

	using grpc::Server;
	using grpc::ServerBuilder;
	using grpc::ServerContext;
	using grpc::Status;
	using grpc::ResourceQuota;
	// Converse
	using Seq2SeqGRPC::Seq2SeqService;
	using Seq2SeqGRPC::ConversationInput;
	using Seq2SeqGRPC::ConversationResponse;
	using Seq2SeqGRPC::ConversationResponse_State;
	// Image
	using ImageClassificationServiceRPC::ImageClassificationService;
	using ImageClassificationServiceRPC::ImageRequest;
	using ImageClassificationServiceRPC::ImageResponse;
	using ImageClassificationServiceRPC::ImageResponse_State;
	// Logic and data behind the server's behavior.
	class Seq2SeqServiceImpl final : public Seq2SeqService::Service {
	private:
		std::unique_ptr<dawn::Seq2Seq> seq2seq;
	public:
		Seq2SeqServiceImpl() {
			seq2seq = std::make_unique<Seq2Seq>();
            seq2seq->Initialize();
		}
		Status RespondToText(ServerContext* context, const ConversationInput* request,
			ConversationResponse* reply) override {
			std::string output = "";
			if (!seq2seq->GenerateReply(request->text(), output)) {
				reply->set_state(ConversationResponse_State::ConversationResponse_State_MODEL_ERR);
				return Status::OK;
			}
			reply->set_state(ConversationResponse_State::ConversationResponse_State_SUCCESS);
			reply->set_text(output);
			return Status::OK;
		}
	};

	class ImageClassificationServiceImpl final : public ImageClassificationService::Service {
	private:
		std::unique_ptr<dawn::ImageClassifier> imageClassifier;
	public:
		ImageClassificationServiceImpl() {
			imageClassifier = std::make_unique<ImageClassifier>();
            imageClassifier->Initialize();
		}
		Status RecognizeImage(ServerContext* context, const ImageRequest* request,
			ImageResponse* reply) override {
			std::string output = "";
			if (!imageClassifier->ClassifyImage(request->image(), output)) {
				reply->set_state(ImageResponse_State::ImageResponse_State_MODEL_ERR);
				return Status::OK;
			}
			reply->set_state(ImageResponse_State::ImageResponse_State_SUCCESS);
			reply->set_text(output); // extract the prediction
			return Status::OK;
		}
	};
	class DawnAI {
	private:
		Seq2SeqServiceImpl converse_service;
		ImageClassificationServiceImpl image_classification_service;
		std::unique_ptr<Server> server;
        int32_t mode = 0;
	public:
		DawnAI() {}
		void Listen(std::string);
        void SetMode(int32_t);
	};
}


#endif