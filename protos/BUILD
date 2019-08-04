load("@build_stack_rules_proto//cpp:cpp_grpc_library.bzl", "cpp_grpc_library")


proto_library(
    name = "converse_service_proto",
    srcs = [
		"converse_service.proto",
	],
	deps = [
        "@com_google_protobuf//:timestamp_proto",
	],
)

proto_library(
    name = "image_recognition_service_proto",
    srcs = [
		"image_recognition_service.proto"
	],
	deps = [
        "@com_google_protobuf//:timestamp_proto",
	],
)

cpp_grpc_library(
    name = "grpc_service_cpp_proto",
	deps = [
		":converse_service_proto",
		":image_recognition_service_proto",
	],
    visibility = ["//visibility:public"],
	
)