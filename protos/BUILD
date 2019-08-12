load("@build_stack_rules_proto//cpp:cpp_grpc_library.bzl", "cpp_grpc_library")


proto_library(
    name = "seq2seq_service_proto",
    srcs = [
		"seq2seq_service.proto",
	],
	deps = [
        "@com_google_protobuf//:timestamp_proto",
	],
)

proto_library(
    name = "image_classification_service_proto",
    srcs = [
		"image_classification_service.proto"
	],
	deps = [
        "@com_google_protobuf//:timestamp_proto",
	],
)

cpp_grpc_library(
    name = "grpc_service_cpp_proto",
	deps = [
		":seq2seq_service_proto",
		":image_classification_service_proto",
	],
    visibility = ["//visibility:public"],
	
)