cc_library(
    name = "DawnAI",
    srcs = ["DawnAI.cpp"],
    hdrs = ["DawnAI.hpp"],
    visibility = ["//src:__pkg__"],
	deps = [
		"//protos:grpc_service_cpp_proto",
		"//src/service:ImageClassifier",
		"//src/service:Seq2Seq",
		"//src/utils:Logger",
	],
)

cc_library(
    name = "KeyWordDetector",
    srcs = ["KeyWordDetector.cpp"],
    hdrs = ["KeyWordDetector.hpp"],
    visibility = [
        "//src:__pkg__",
        "//src/service:__pkg__",
    ],
)




