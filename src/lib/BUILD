cc_library(
    name = "TorchDawn",
    srcs = ["TorchDawn.cpp"],
    hdrs = ["TorchDawn.hpp"],
	deps = [
		"@torch//:torch",
		"@spdlog//:spdlog",
	],
    visibility = ["//src/lib:__pkg__"],
)

cc_library(
    name = "DawnAI",
    srcs = ["DawnAI.cpp"],
    hdrs = ["DawnAI.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		"//protos:grpc_service_cpp_proto",
		"//src/lib:ImageClassifier",
		"//src/lib:Seq2Seq",
		"//src/utils:Logger",
	],
)
cc_library(
    name = "ImageClassifier",
    srcs = ["ImageClassifier.cpp"],
    hdrs = ["ImageClassifier.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		
		"//src/utils:ImageUtils",
		"@torch//:torch",
		"//src/lib:TorchDawn",
		"@websocketpp//:websocketpp",
		"@opencv4//:opencv4",
		"//src/utils:Logger",
	],
)
cc_library(
    name = "KeyWordDetector",
    srcs = ["KeyWordDetector.cpp"],
    hdrs = ["KeyWordDetector.hpp"],
    visibility = ["//src:__pkg__"],
)
cc_library(
    name = "Seq2Seq",
    srcs = ["Seq2Seq.cpp"],
    hdrs = ["Seq2Seq.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		"//src/lib:KeyWordDetector",
		"//src/utils:StringUtils",	
				
		"@torch//:torch",
		"//src/lib:TorchDawn",
		"//src/utils:Logger",
		"@json//:json",
	],
	data = [
        "//src/model/imageClassifier:image_classifier_data",
		"//src/model/seq2seq:seq2seq_data",
    ],
)



