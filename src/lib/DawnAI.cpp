#include "DawnAI.hpp"

#include <iostream>
#include <string>
#include <memory>

#include <grpc++/grpc++.h>
#include <grpc++/resource_quota.h>
#include "protos/image_classification_service.grpc.pb.h"
#include "protos/seq2seq_service.grpc.pb.h"

#include "src/utils/Logger.hpp"
#include "src/service/SequenceToSequence.hpp"
#include "src/service/ImageClassifier.hpp"

namespace dawn{

/**
 * @brief only 1 service at a time.
 * So either image classification or converse
 */
void DawnAI::SetMode(int32_t inputMode) {
	mode = inputMode;
}

void DawnAI::Listen(std::string addr) {
	std::string server_address(addr);
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
    DAWN_INFO("Listening on " << server_address);
	// Wait for the server to shutdown. Note that some other thread must be
	// responsible for shutting down the server for this call to ever return.
	server->Wait();
}


}
