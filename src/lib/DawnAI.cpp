#include "DawnAI.hpp"

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

namespace dawn{
	DawnAI::DawnAI() {
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
		mainLogger = spdlog::stdout_color_mt("Main Logger");
		
		textGenerator = std::make_shared<dawn::TextGenerator>();
		imageInferencer = std::make_shared<dawn::ImageInference>();
	}

	void DawnAI::listen(std::string PORT) {
		std::string server_address("0.0.0.0:" + PORT);
		ServerBuilder builder;
		// Listen on the given address without any authentication mechanism.
		builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
		// Register "service" as the instance through which we'll communicate with
		// clients. In this case it corresponds to an *synchronous* service.
		builder.RegisterService(&service);
		// Finally assemble the server.
		std::unique_ptr<Server> server(builder.BuildAndStart());
		mainLogger->info("Listening on " + server_address);

		// Wait for the server to shutdown. Note that some other thread must be
		// responsible for shutting down the server for this call to ever return.
		server->Wait();
	}

}
