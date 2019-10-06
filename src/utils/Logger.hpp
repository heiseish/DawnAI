#pragma once

#ifndef DAWNLOGGER_H 
#define DAWNLOGGER_H

#include <chrono>
#include <string>
#include <iostream>
#include <ctime>   

namespace dawn {

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define _GREEN "\033[0;92m"
#define _RED "\033[0;91m"
#define _BROWN "\033[0;93m"
#define _MAGNETA "\033[0;95m"
#define _CYAN "\033[0;96m"
#define _RESET "\033[0m"
#define DAWN_INFO(x) DAWN_LOG(_GREEN, " INFO  ", x)
#define DAWN_DEBUG(x) DAWN_LOG(_BROWN, " DEBUG ", x)
#define DAWN_ERROR(x) DAWN_LOG(_RED, " ERROR ", x)

#define DAWN_LOG(col, text_info, x) { \
    auto cur = std::chrono::system_clock::now(); \
    std::time_t cur_t = std::chrono::system_clock::to_time_t(cur);  \
    std::cout << _CYAN << strtok(std::ctime(&cur_t), "\n") << _RESET << " - " <<  col << '[' << text_info << ']' << _RESET  \
    << " - " << _MAGNETA << __FUNCTION__ << _RESET << " - " << __FILENAME__ << ":" << __LINE__ << ": " << x << std::endl; \
}

}
#endif