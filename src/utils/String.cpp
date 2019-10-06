#include "String.hpp"

#include <string>
#include <vector>

namespace dawn {
/** 
* Lowercase, trim, and remove non-letter characters
*/
void StringUtil::NormalizeString(std::string& output, const std::string& input) {
	output.clear();
	for(int i = 0; i < (int) input.length(); ++i) {
		char ch = input[i];
		if (isalpha(ch) || isdigit(ch)) {
			output.push_back(tolower(ch));
		} else if (ch == '%' && i < (int) input.length() - 2 && input[i + 1] == '2' && input[i + 2] == '0') {
			output.push_back(' ');
			i += 2;
		} else if (isspace(ch) || ispunct(ch)) {
			output.push_back(ch);
		}
	}
}



void StringUtil::Split(std::vector<std::string>& tokens, const std::string& str, const std::string& delim) {
    tokens.clear();
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
}

}



