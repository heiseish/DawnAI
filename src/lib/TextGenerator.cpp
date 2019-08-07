#include "TextGenerator.hpp"

#include <torch/script.h>
#include <torch/torch.h>

#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#include "KeyWordDetector.hpp"
#include "src/utils/StringUtils.hpp"
#include "TorchDawn.hpp"
#include <json.hpp>


#include "src/utils/Logger.hpp"

namespace dawn {

TextGenerator::TextGenerator(const std::string& path, const std::string& profanityCollection) {
	logger = std::make_shared<Logger>("Text Generator");
	module = std::make_unique<TorchDawn>(path, ready);
	if (!ready) logger->error("Text generator model load fails!");
	else logger->info("Text generator model loaded successfully");

	currentStringUtils = std::make_shared<StringUtils>();
	profanityDetector = std::make_shared<KeyWordDetector>();

	std::ifstream profanityJSON (profanityCollection, std::ifstream::binary);
	auto f = nlohmann::json::parse(profanityJSON);
	int count = 1;
	for (auto &word : f) {
		profanityDetector->addString(word.get<std::string>(), count++);
	}

}

bool TextGenerator::generateReply(const std::string& input, std::string& output) {
	if (!ready) {
		return false;
	}
	logger->info(input);

	std::string normalizedString = currentStringUtils->normalizeString(input);

	std::vector<std::vector<int> > prof = profanityDetector->searchForOccurenceInString(normalizedString); // occurence of profanity
	
	std::vector<int64_t> indexes = currentStringUtils->indexesFromSentence(normalizedString);
	int64_t length = indexes.size();
	at::TensorOptions options(at::ScalarType::Long);
	// convert temp into length x 1 Tensor
	auto inputSequence = torch::from_blob(indexes.data(), { length, 1 }, options);
	std::vector<int64_t> lengthVector { length };
	auto lengthTensor = torch::from_blob(lengthVector.data(), { 1 } , options);

	// // Execute the model and turn its output into a tensor.
	std::vector<int64_t> model_output;
	std::vector<c10::IValue> model_input { inputSequence, lengthTensor, MAX_LENGTH};
	if (!module->forward(model_input, model_output, 1)) {
		logger->error("Generating text fails");
		return false;
	}
	output = currentStringUtils->sentenceFromIndexes(model_output);
	return  true;
}

}
