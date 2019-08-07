#include "Logger.hpp"
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <chrono>
#include <string>
#include <stack>
#include <time.h> 
namespace dawn {

Logger::Logger(const char* loggerName) {
	spdlog::set_pattern("[%H:%M:%S] [%n] [%^---%L---%$] %v");
	logger = spdlog::stdout_color_mt(loggerName); 
}
Logger::~Logger() {
	clean();
}
void Logger::info(const char* message) {
	logger->info(message);
}
void Logger::info(const std::string& message) {
	logger->info(message);
}
void Logger::warn(const char* message) {
	logger->warn(message);
}
void Logger::warn(const std::string& message) {
	logger->warn(message);
}
void Logger::error(const char* message) {
	logger->error(message);
}
void Logger::error(const std::string& message) {
	logger->error(message);
}
void Logger::start(const char* verb, const char* target) {
	startTimes.push(std::chrono::high_resolution_clock::now());
	std::string _verb(verb), _target(target);
	actions.push(_verb + "-ing " + _target); // COPY could take long
	logger->info(actions.top());
}
void Logger::start(const std::string& verb, const std::string& target) {
	startTimes.push(std::chrono::high_resolution_clock::now());
	actions.push(verb + "-ing " + target); // COPY could take long
	logger->info(actions.top());
}

void Logger::start(const char* verb) {
	startTimes.push(std::chrono::high_resolution_clock::now());
	actions.push(std::string(verb)); // COPY could take long
	logger->info(actions.top());
}

void Logger::start(const std::string& verb) {
	startTimes.push(std::chrono::high_resolution_clock::now());
	actions.push(std::string(verb)); // COPY could take long
	logger->info(actions.top());
}

void Logger::end() {
	if (startTimes.empty() || actions.empty()) {
		logger->warn("Unable to record execution time since the timer was not started");
		return;
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto& start = startTimes.top();
	startTimes.pop();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>( endTime - start ).count();
    logger->info("Finished " + actions.top() + " in " + std::to_string(duration) + "us");
	actions.pop();
}

void Logger::clean() {
	startTimes = {};
	actions = {};

}
	
}