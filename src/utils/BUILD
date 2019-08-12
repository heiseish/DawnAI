cc_library(
    name = "ImageUtils",
    srcs = ["ImageUtils.cpp"],
    hdrs = ["ImageUtils.hpp"],
	deps = [
		"@curl//:curl",
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
