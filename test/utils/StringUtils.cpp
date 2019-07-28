#include <dawn/utils/StringUtils.hpp>

#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <json.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( normalizeStringTest ) {
	dawn::StringUtils util;
    auto s = util.normalizeString("Hello, Its ME");
    BOOST_CHECK_EQUAL( s, "hello, its me" );
}


BOOST_AUTO_TEST_CASE( indexesFromSentenceTest ) {
	std::unordered_map<std::string, long long> word2index;
	std::ifstream ifsw2i("src/model/word2index.json", std::ifstream::binary);
	auto f = nlohmann::json::parse(ifsw2i);
	for (auto& [key, value] : f.items()) {
		word2index[key] = value;
	}
	std::vector<std::string> testWords { "Hello", "from", "the", "other", "side"};
	std::string concatenatedString = "";
	for (auto &v : testWords) {
		concatenatedString += v;
		concatenatedString += " ";
	}

	dawn::StringUtils util;
	std::vector<int64_t> res = util.indexesFromSentence(concatenatedString);
	int length =  testWords.size();
	for(int i = 0; i < length; ++i) {
		 BOOST_CHECK_EQUAL( word2index[testWords[i]], res[i] );
	}


}

BOOST_AUTO_TEST_CASE( sentenceFromIndexesTest ) {
	std::unordered_map<long long, std::string> index2word;
	std::unordered_map<std::string, long long> word2index;
	std::ifstream ifsw2i("src/model/word2index.json", std::ifstream::binary);
	auto f = nlohmann::json::parse(ifsw2i);
	for (auto& [key, value] : f.items()) {
		word2index[key] = value;
	}

	std::ifstream ifsi2w("src/model/index2word.json", std::ifstream::binary);
	auto s = nlohmann::json::parse(ifsi2w);
	for (auto& [key, value] : s.items()) {
		index2word[stoll(key)] = value;
	}


	std::vector<std::string> testWords { "hello", "from", "the", "other", "side"};
	std::vector<int64_t> indexes;
	for (auto &v : testWords) 
		indexes.emplace_back(word2index[v]);

	indexes.emplace_back(dawn::StringUtils::EOS_token);
	for(int i = 1; i < 10; ++i)
		indexes.emplace_back(rand() % 1000);

	dawn::StringUtils util;
	std::string result = util.sentenceFromIndexes(indexes);


	std::string concatenatedString = "";
	for (int i = 0; i < testWords.size(); ++i) {
		concatenatedString += testWords[i];
		concatenatedString += " ";
	}
	BOOST_CHECK_EQUAL( result, concatenatedString );

}




