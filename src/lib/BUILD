cc_library(
    name = "DawnAI",
    srcs = ["DawnAI.cpp"],
    hdrs = ["DawnAI.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		"//protos:text_generator_service_cc_proto",
		"//src/lib:ImageInference",
		"//src/lib:TextGenerator",
		"@spdlog//:spdlog",
	],
)
cc_library(
    name = "ImageInference",
    srcs = ["ImageInference.cpp"],
    hdrs = ["ImageInference.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		"//src/utils:PytorchUtils",	
		"//src/utils:OpenCVUtils",
		"@torch//:torch",
		"@spdlog//:spdlog",
		"@websocketpp//:websocketpp",
		"@opencv4//:opencv4",
	],
)
cc_library(
    name = "KeyWordDetector",
    srcs = ["KeyWordDetector.cpp"],
    hdrs = ["KeyWordDetector.hpp"],
    visibility = ["//src:__pkg__"],
)
cc_library(
    name = "TextGenerator",
    srcs = ["TextGenerator.cpp"],
    hdrs = ["TextGenerator.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		"//src/lib:KeyWordDetector",
		"//src/utils:StringUtils",	
		"//src/utils:PytorchUtils",	
		"@torch//:torch",
		"@spdlog//:spdlog",	
		"@json//:json",
	],
)


