cc_library(
    name = "opencv4",
    srcs = glob([
        "lib/**/*.so*",
        "lib/**/*.a*",
    ]),
    hdrs = glob([
		"include/**/*.hpp",
		"include/**/*.h",
	]),
    includes = [
        "include/opencv4"
    ],
    visibility = ["//visibility:public"], 
    linkstatic = 1,
)