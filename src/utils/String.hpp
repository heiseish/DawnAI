#pragma once

#ifndef STRING_UTILS_H
#define STRING_UTILS_H


#include <string>
#include <vector>


namespace dawn {

class StringUtil {
public:
    /**
     * @brief split string into token with delimiter
     */
    static void Split(std::vector<std::string>& output, const std::string& str, const std::string& delim=",");
	/** 
	* @brief Lowercase, trim, and remove non-letter characters
    * @param string to normalize
	*/
	static void NormalizeString(std::string& output, const std::string&);
private:
    StringUtil() {}// disable instantiate
	
};

}








#endif
