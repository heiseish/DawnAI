cc_library(
    name = "curl",
	 srcs = glob([
        "lib/**/*.so*",
        "lib/**/*.a*",
    ]),
	hdrs = glob(["include/**/*.h"]),
	includes = [
        "include",
    ],
    visibility = ["//visibility:public"], 
    linkstatic = 1,
)