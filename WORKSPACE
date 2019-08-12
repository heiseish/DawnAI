load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# This com_google_protobuf repository is required for proto_library rule.
# It provides the protocol compiler binary (i.e., protoc).
http_archive(
    name = "com_google_protobuf",
    strip_prefix = "protobuf-master",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
)

# This com_google_protobuf_cc repository is required for cc_proto_library
# rule. It provides protobuf C++ runtime. Note that it actually is the same
# repo as com_google_protobuf but has to be given a different name as
# required by bazel.
http_archive(
    name = "com_google_protobuf_cc",
    strip_prefix = "protobuf-master",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/9dfbd34f5c0b20bd77658c73c59b9a3e4e8f4e14.tar.gz",
    ],
    strip_prefix = "grpc-9dfbd34f5c0b20bd77658c73c59b9a3e4e8f4e14",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

http_archive(
    name = "build_stack_rules_proto",
    urls = ["https://github.com/stackb/rules_proto/archive/b93b544f851fdcd3fc5c3d47aee3b7ca158a8841.tar.gz"],
    sha256 = "c62f0b442e82a6152fcd5b1c0b7c4028233a9e314078952b6b04253421d56d61",
    strip_prefix = "rules_proto-b93b544f851fdcd3fc5c3d47aee3b7ca158a8841",
)
# WORKSPACE
load("@build_stack_rules_proto//cpp:deps.bzl", "cpp_proto_library")

cpp_proto_library()

new_local_repository(
    name = "torch",
    path = "dep/torch",
    build_file = "3rdparty_buildfiles/torch.BUILD",
)

new_local_repository(
    name = "opencv4",
    path = "dep/opencv4",
    build_file = "3rdparty_buildfiles/opencv4.BUILD",
)

new_local_repository(
    name = "spdlog",
    path = "dep/spdlog",
    build_file = "3rdparty_buildfiles/spdlog.BUILD",
)

new_local_repository(
    name = "json",
    path = "dep/json",
    build_file = "3rdparty_buildfiles/json.BUILD",
)

new_local_repository(
    name = "curl",
    path = "dep/curl",
    build_file = "3rdparty_buildfiles/curl.BUILD",
)

new_local_repository(
    name = "websocketpp",
    path = "dep/websocketpp",
    build_file = "3rdparty_buildfiles/websocketpp.BUILD",
)

