#pragma once

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <regex>
#include <unordered_map>
#include <string>
#include <fstream>

#include <json.hpp>

namespace dawn {

class StringUtils {
private:
	std::unordered_map<std::string, int64_t> word2index;
	std::unordered_map<int64_t, std::string> index2word;
public:
	static const int PAD_token = 0;  // Used for padding short sentences
	static const int SOS_token = 1;  // Start-of-sentence token
	static const int EOS_token = 2;  // End-of-sentence token
	static const int MIN_COUNTs = 3;  // Minimum word count threshold for trimming
	static const int MAX_LENGTH = 10;  // Maximum sentence length to consider
	StringUtils(const std::string& word2indexPath="src/model/word2index.json", 
		const std::string& index2wordPath="src/model/index2word.json");
	/** 
	* Lowercase, trim, and remove non-letter characters
	*/
	std::string normalizeString(const std::string&);
	std::vector<int64_t> indexesFromSentence(const std::string&);
	std::string sentenceFromIndexes(const std::vector<int64_t>&);
	std::string getWord(const int64_t&);
};

}








#endif
