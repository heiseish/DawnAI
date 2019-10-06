#include "lib/DawnAI.hpp"
#include <gflags/gflags.h>
#include <iostream>
#include <fmt/format.h>

// docker should be 0.0.0.0
DEFINE_string(address, "127.0.0.1", "IPv4 Address of the gRPC server");
DEFINE_string(port, "8080", "Port to listen");
DEFINE_int32(neural_net, 0, "0: Image classifier, 1: Text generator, 2: TBC");

int main(int argc, char* argv[]) {
	dawn::DawnAI app;
    app.SetMode(FLAGS_neural_net);
	app.Listen(fmt::format("{}:{}", FLAGS_address, FLAGS_port));
	return 0;
}

