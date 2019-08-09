#pragma once

#ifndef DAWNLOGGER_H 
#define DAWNLOGGER_H

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <chrono>
#include <string>
#include <stack>
namespace dawn {
class Logger {
private:
	std::shared_ptr<spdlog::logger> logger;
	std::stack<std::chrono::time_point<std::chrono::high_resolution_clock> > startTimes;
	std::stack<std::string> actions;
public:
	Logger(const char*);
	~Logger();
	void info(const char*);
	void info(const std::string&);

	void warn(const char*);
	void warn(const std::string&);

	void error(const char*);
	void error(const std::string&);

	void debug(const char*);
	void debug(const std::string&);
	

	void start(const char*, const char*);
	void start(const char*);

	void start(const std::string&, const std::string&);
	void start(const std::string&);

	void end();
	void clean();
};

}
#endif