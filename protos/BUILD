load("@build_stack_rules_proto//cpp:cpp_grpc_library.bzl", "cpp_grpc_library")

proto_library(
    name = "text_generator_service_proto",
    srcs = ["text_generator_service.proto"],
#    deps = ["@com_google_protobuf//:timestamp_proto"],
)

cpp_grpc_library(
    name = "text_generator_service_cc_proto",
    deps = [":text_generator_service_proto"],
    visibility = ["//visibility:public"],
)