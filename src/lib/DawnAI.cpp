#include "DawnAI.hpp"

#include <iostream>
#include <string>
#include <memory>

#include <grpc++/grpc++.h>
#include <grpc++/resource_quota.h>
#include "protos/image_classification_service.grpc.pb.h"
#include "protos/seq2seq_service.grpc.pb.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "src/utils/Logger.hpp"
#include "Seq2Seq.hpp"
#include "ImageClassifier.hpp"

namespace dawn{

DawnAI::DawnAI() {
	logger = std::make_shared<Logger>("Dawn");
}

void DawnAI::listen(std::string PORT) {
	auto mode = std::getenv("MODE");
	std::string IPaddr = strcmp(mode, "docker")  == 0 ? "0.0.0.0:" : "127.0.0.1:";
	std::string server_address(IPaddr + PORT);
	ServerBuilder builder;
	ResourceQuota resource_quota;
	resource_quota.SetMaxThreads(2);

	// builder.SetMaxReceiveMessageSize(INT_MAX); // TODO need to benchmark to see whether it slows down connection
	builder.SetResourceQuota(resource_quota);
	// Listen on the given address without any authentication mechanism.
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	// Register "service" as the instance through which we'll communicate with
	// clients. In this case it corresponds to an *synchronous* service.
	builder.RegisterService(&converse_service);
	builder.RegisterService(&image_classification_service);
	// Finally assemble the server.
	server = builder.BuildAndStart();
	logger->info("Listening on " + server_address);
	// Wait for the server to shutdown. Note that some other thread must be
	// responsible for shutting down the server for this call to ever return.
	server->Wait();
}

}
