cc_library(
    name = "ImageClassificationGRPC",
    srcs = [
        "image_classification_service.grpc.pb.cc",
        "image_classification_service.pb.cc"
    ],
    hdrs = [
        "image_classification_service.grpc.pb.h",
        "image_classification_service.pb.h"
    ],
    deps = [
        "@protobuf//:protobuf",
        "@grpc//:grpc",
	],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "Sequence2SequenceGRPC",
    srcs = [
        "seq2seq_service.grpc.pb.cc",
        "seq2seq_service.pb.cc"
    ],
    hdrs = [
        "seq2seq_service.grpc.pb.h",
        "seq2seq_service.pb.h"
    ],
    deps = [
        "@protobuf//:protobuf",
        "@grpc//:grpc",
	],
    visibility = ["//visibility:public"],
)