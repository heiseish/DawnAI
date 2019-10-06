cc_library(
    name = "Seq2Seq",
    srcs = ["SequenceToSequence.cpp"],
    hdrs = ["SequenceToSequence.hpp"],
    visibility = [
        "//src/lib:__pkg__",
    ],
	deps = [
		"//src/utils:StringUtil",	
        "//src/engines/specific:InferenceEngine",
		"//src/engines/specific:TorchEngine",	
        "//src/engines/specific:InferenceBlob",
		"//src/utils:Logger",
        "@torch//:torch",
		"@json//:json",
        "@fmt//:fmt"
	],
	data = [
		"//src/model/seq2seq:seq2seq_data",
    ],
)

cc_library(
    name = "ImageClassifier",
    srcs = ["ImageClassifier.cpp"],
    hdrs = ["ImageClassifier.hpp"],
    visibility = [
         "//src/lib:__pkg__",
    ],
	deps = [
		"//src/utils:ImageUtil",
        "//src/engines/specific:InferenceEngine",
        "//src/engines/specific:TorchEngine",	
        "//src/engines/specific:InferenceBlob",
        "//src/utils:Logger",
        "@torch//:torch",
		"@websocketpp//:websocketpp",
		"@opencv4//:opencv4",
		
	],
    data = [
		"//src/model/imageClassifier:image_classifier_data",
    ],
)