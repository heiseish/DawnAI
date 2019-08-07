cc_library(
    name = "TorchDawn",
    srcs = ["TorchDawn.cpp"],
    hdrs = ["TorchDawn.hpp"],
	deps = [
		"@torch//:torch",
		"@spdlog//:spdlog",
	],
	data = [
        "//src/model:torch_model",
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
		"//src/lib:ImageInference",
		"//src/lib:TextGenerator",
		"//src/utils:Logger",
	],
)
cc_library(
    name = "ImageInference",
    srcs = ["ImageInference.cpp"],
    hdrs = ["ImageInference.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		
		"//src/utils:OpenCVUtils",
		"@torch//:torch",
		"//src/lib:TorchDawn",
		"@websocketpp//:websocketpp",
		"@opencv4//:opencv4",
		"//src/utils:Logger",
	],
	data = [
        "//src/model:torch_model",
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
				
		"@torch//:torch",
		"//src/lib:TorchDawn",
		"//src/utils:Logger",
		"@json//:json",
	],
	data = [
        "//src/model:torch_model",
    ],
)



