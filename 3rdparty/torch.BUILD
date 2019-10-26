cc_library(
    name = "torch",
    srcs = glob([
        "lib/**/*.so*",
        "lib/**/*.a*",
    ]),
    hdrs = glob(["include/**/*.h"]),
    includes = [
        "include",
        "include/torch/csrc/api/include",
        "include/TH",
        "include/THC",
        "include/c10",
    ],
    visibility = ["//visibility:public"], 
    linkstatic = 1,
)