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

bool TorchEngine::Initialize(const InferenceResource& resource) {	
    try {
        if (!resource.count(INFERENCE_ENGINE_MODEL_PATH)) {
            DAWN_ERROR("Path not present in the InferenceResource!");
            return false;
        }
        auto model_path = boost::any_cast<std::string>(resource.at(INFERENCE_ENGINE_MODEL_PATH));
        model = std::make_shared<torch::jit::script::Module>(torch::jit::load(model_path));
    } catch (const std::exception& e) {
        DAWN_ERROR(e.what());
        return false;
    } catch (...) {
        return false;
    }
    return true;	
}



bool TorchEngine::Forward(InferenceOutput& ouput, const InferenceInput& input) const {
	DAWN_ERROR("Not implemented");
    return false;
}

/**
 * @brief Torch engine doesn't have input name due to script tracing
 */
bool TorchEngine::Forward(c10::IValue& output, const torch::jit::Stack& input) const {
	try {
        torch::NoGradGuard noGrad;
		output = model->forward(input);
        return true;
    } catch (const std::exception& e) {
        DAWN_ERROR(e.what());
        return false;
	} catch(...) {
		return false;
	}
	
}


}