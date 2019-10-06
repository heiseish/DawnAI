cc_library(
    name = "ImageUtil",
    srcs = ["Image.cpp"],
    hdrs = ["Image.hpp"],
	deps = [
		"@curl//:curl",
		"@opencv4//:opencv4",
        "//src/utils:Logger",
	],
    visibility = [
        "//src/lib:__pkg__",
        "//src/service:__pkg__"
    ],
)
cc_library(
    name = "StringUtil",
    srcs = ["String.cpp"],
    hdrs = ["String.hpp"],
	deps = [
        "//src/utils:Logger",
	],
    visibility = [
        "//src/lib:__pkg__",
        "//src/engines/specific:__pkg__",
        "//src/service:__pkg__"
    ],
)

cc_library(
    name = "Logger",
    hdrs = ["Logger.hpp"],
    visibility = [
        "//src/lib:__pkg__",
        "//src/engines/specific:__pkg__",
        "//src/service:__pkg__"
    ],
)
