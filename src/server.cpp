#include "lib/DawnAI.hpp"
#include <string>

int main(int argc, char* argv[]) {
	dawn::DawnAI app;
	const char* port = std::getenv("PORT");
    const std::string port_string(port);
	app.listen(port_string);
	return 0;
}

