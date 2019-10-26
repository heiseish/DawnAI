cc_library(
    name = "protobuf",
    srcs = glob([
        "lib/**/*.so*",
        "lib/**/*.a*",
    ]),
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.inc",
    ]),
    includes = [
        "include"
    ],
    visibility = ["//visibility:public"], 
    linkstatic = 1,
)