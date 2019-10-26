cc_library(
    name = "grpc",
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
    linkopts = [ 
        "-lpthread",
        "-lz" 
    ],
    visibility = ["//visibility:public"], 
    linkstatic = 1,
)