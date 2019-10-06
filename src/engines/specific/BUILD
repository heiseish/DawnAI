cc_library(
    name = "InferenceBlob",
    hdrs = ["InferenceBlob.hpp"],
    visibility = [
        "//src/lib:__pkg__",
        "//src/engines/specific:__pkg__",
        "//src/service:__pkg__"
    ],
)

cc_library(
    name = "InferenceEngine",
    hdrs = ["InferenceEngine.hpp"],
	deps = [
		"//src/engines/specific:InferenceBlob",
	],
    visibility = [
        "//src/engines/specific:__pkg__",
        "//src/service:__pkg__"
    ],
)

cc_library(
    name = "TorchEngine",
    srcs = ["TorchEngine.cpp"],
    hdrs = ["TorchEngine.hpp"],
	deps = [
		"//src/engines/specific:InferenceBlob",
        "//src/engines/specific:InferenceEngine",
        "//src/utils:StringUtil",
        "//src/utils:Logger",
        "@torch//:torch",
	],
    visibility = [
        "//src/lib:__pkg__",
        "//src/service:__pkg__"
    ],
    data = [
		"//src/model/seq2seq:seq2seq_data",
        "//src/model/imageClassifier:image_classifier_data",
    ],
)
