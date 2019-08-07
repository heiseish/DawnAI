cc_library(
    name = "OpenCVUtils",
    srcs = ["OpenCvUtils.cpp"],
    hdrs = ["OpenCvUtils.hpp"],
	deps = [
		"@opencv4//:opencv4",
	],
    visibility = ["//src/lib:__pkg__"],
)
cc_library(
    name = "StringUtils",
    srcs = ["StringUtils.cpp"],
    hdrs = ["StringUtils.hpp"],
	deps = [
		"@json//:json",
	],
    visibility = ["//src/lib:__pkg__"],
)

cc_library(
    name = "Logger",
    srcs = ["Logger.cpp"],
    hdrs = ["Logger.hpp"],
	deps = [
		"@spdlog//:spdlog",
	],
    visibility = ["//src/lib:__pkg__"],
)
