#include "utils/StringUtils.hpp"

#include <regex>
#include <unordered_map>
#include <string>
#include <fstream>

#include <json.hpp>

const int dawn::StringUtils::PAD_token;
const int dawn::StringUtils::SOS_token;
const int dawn::StringUtils::EOS_token;
const int dawn::StringUtils::MIN_COUNTs;
const int dawn::StringUtils::MAX_LENGTH;

dawn::StringUtils::StringUtils (const std::string& word2indexPath, const std::string& index2wordPath) {
	std::ifstream ifsw2i(word2indexPath, std::ifstream::binary);
	auto f = nlohmann::json::parse(ifsw2i);
	for (auto& [key, value] : f.items()) {
		word2index[key] = value;
	}
	std::ifstream ifsi2w(index2wordPath, std::ifstream::binary);
	auto s = nlohmann::json::parse(ifsi2w);
	for (auto& [key, value] : s.items()) {
		index2word[stoll(key)] = value;
	}
}

/** 
* Lowercase, trim, and remove non-letter characters
*/
std::string dawn::StringUtils::normalizeString(const std::string& input) {
	std::string result;
	for(int i = 0; i < input.length(); ++i) {
		char ch = input[i];
		if (isalpha(ch) || isdigit(ch)) {
			result.push_back(tolower(ch));
		} else if (ch == '%' && i < input.length() - 2 && input[i + 1] == '2' && input[i + 2] == '0') {
			result.push_back(' ');
			i += 2;
		} else if (isspace(ch) || ispunct(ch)) {
			result.push_back(ch);
		}
	}
	return result;
}


std::vector<int64_t> dawn::StringUtils::indexesFromSentence(const std::string& sentence) {
	const int EOS_token = 2;
	std::regex rg("\\s+");

	std::vector<std::string> out(
	std::sregex_token_iterator(sentence.begin(), sentence.end(), rg, -1),
	std::sregex_token_iterator()
	);
	std::vector<int64_t> ans(out.size());
	for(int i = 0; i < out.size(); ++i) {
		ans[i] = word2index[out[i]];
	}
	ans.emplace_back(EOS_token);
	return ans;
}

std::string dawn::StringUtils::sentenceFromIndexes(const std::vector<int64_t>& indexes) {
	std::string ans = "";
	for (auto &v : indexes) {
		if (v == EOS_token) break; //EOS
		ans += index2word[v];
		ans += ' ';
	}
	return ans;
}


