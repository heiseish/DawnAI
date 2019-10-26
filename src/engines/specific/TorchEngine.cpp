#include "TorchEngine.hpp"
#include "InferenceBlob.hpp"

#include <string>

#include <torch/script.h>
#include <torch/serialize/tensor.h>
#include <torch/serialize.h>
#include <torch/utils.h>
#include "src/utils/Logger.hpp"
#include "src/utils/String.hpp"

namespace dawn {

bool TorchEngine::Initialize(const InferenceResource& resource)  {	
    try {
        if (!resource.count(INFERENCE_ENGINE_MODEL_PATH)) {
            DAWN_ERROR << "Path not present in the InferenceResource!\n";
            return false;
        }
        auto model_path = boost::any_cast<std::string>(resource.at(INFERENCE_ENGINE_MODEL_PATH));
        model = std::make_shared<torch::jit::script::Module>(torch::jit::load(model_path));
    } catch (const std::exception& e) {
        DAWN_ERROR << e.what() << std::endl;
        return false;
    } catch (...) {
        return false;
    }
    return true;	
}


/**
 * @brief Torch engine doesn't have input name due to script tracing
 */
bool TorchEngine::Forward(InferenceOutput<c10::IValue>& output, const InferenceInput<c10::IValue>& input) const {
	try {
        torch::NoGradGuard noGrad;
        output.clear();
        auto tempOutput =  model->forward(input.begin()->second);
        std::vector<c10::IValue> outputStore;
        outputStore.emplace_back(std::move(tempOutput));
		output.emplace("0", std::move(outputStore));
        return true;
    } catch (const std::exception& e) {
        DAWN_ERROR << e.what() << std::endl;
        return false;
	} catch(...) {
		return false;
	}
	
}


}