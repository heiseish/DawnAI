#include "TextGenerator.hpp"

#include <torch/script.h>
#include <torch/torch.h>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "KeyWordDetector.hpp"
#include "src/utils/StringUtils.hpp"
#include "src/utils/PytorchUtils.hpp"
#include <json.hpp>


#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

dawn::TextGenerator::TextGenerator(const char* path, const char* profanityCollection) {
	textGeneratorInputLogger = spdlog::stdout_color_mt("Input text");
	textGeneratorResponseLogger = spdlog::stdout_color_mt("Response Text");

	module = dawn::readModel(path);
	if (module.get() == nullptr) {
		textGeneratorInputLogger->warn("Path to model is not valid");
	} else textGeneratorInputLogger->info("Text classifier loaded successfully");

	currentStringUtils = std::make_shared<dawn::StringUtils>();
	profanityDetector = std::make_shared<dawn::KeyWordDetector>();

	std::ifstream profanityJSON (profanityCollection, std::ifstream::binary);
	auto f = nlohmann::json::parse(profanityJSON);
	int count = 1;
	for (auto &word : f) {
		profanityDetector->addString(word.get<std::string>(), count++);
	}

}

std::string dawn::TextGenerator::generateReply(const std::string& s, 
	const int MAX_LENGTH) {
	textGeneratorInputLogger->info(s);

	std::string r = currentStringUtils->normalizeString(s);
	std::vector<std::vector<int> > prof = profanityDetector->searchForOccurenceInString(r); // occurence of profanity
	
	std::vector<int64_t> indexes = currentStringUtils->indexesFromSentence(r);
	int64_t length = indexes.size();
	at::TensorOptions options(at::ScalarType::Long);
	// convert temp into length x 1 Tensor
	auto inputSequence = torch::from_blob(indexes.data(), { length, 1 }, options);
	std::vector<int64_t> lengthVector { length };
	auto lengthTensor = torch::from_blob(lengthVector.data(), { 1 } , options);

	// // Execute the model and turn its output into a tensor.
	auto output = module->forward({ inputSequence, lengthTensor, MAX_LENGTH}).toTuple()->elements();
	int64_t size = output[0].toTensor().size(0);
	auto mem = output[0].toTensor().data<int64_t>();
	std::vector<int64_t> integerOutput(mem, mem + size);

	std::string answer = currentStringUtils->sentenceFromIndexes(integerOutput);
	textGeneratorResponseLogger->info(answer);
	return  answer;
}