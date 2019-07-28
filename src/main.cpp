#include "lib/DawnAI.hpp"
#include <string>

int main(int argc, const char* argv[]) {	
	dawn::DawnAI app;
    // char* port = std::getenv("PORT");
    // const std::string port_string(port);
	// app.listen(std::stoi(port_string));
    app.listen(8080);
	return 0;
}
