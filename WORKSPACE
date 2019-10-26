load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# -------------------- Boost ----------------------------
git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "76f30649e9156b4a29f6074b856fc29a6046e79d",
    remote = "https://github.com/nelhage/rules_boost",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

# -------------------- Compiled dependencies ----------------------------
new_local_repository(
    name = "torch",
    path = "dep/torch",
    build_file = "3rdparty/torch.BUILD",
)

new_local_repository(
    name = "opencv4",
    path = "dep/opencv4",
    build_file = "3rdparty/opencv4.BUILD",
)

new_local_repository(
    name = "spdlog",
    path = "dep/spdlog",
    build_file = "3rdparty/spdlog.BUILD",
)

new_local_repository(
    name = "json",
    path = "dep/json",
    build_file = "3rdparty/json.BUILD",
)

new_local_repository(
    name = "curl",
    path = "dep/curl",
    build_file = "3rdparty/curl.BUILD",
)

new_local_repository(
    name = "websocketpp",
    path = "dep/websocketpp",
    build_file = "3rdparty/websocketpp.BUILD",
)

new_local_repository(
    name = "fmt",
    path = "dep/fmt",
    build_file = "3rdparty/fmt.BUILD",
)

new_local_repository(
    name = "gflag",
    path = "dep/gflag",
    build_file = "3rdparty/gflag.BUILD",
)

new_local_repository(
    name = "protobuf",
    path = "dep/protobuf",
    build_file = "3rdparty/protobuf.BUILD",
)

new_local_repository(
    name = "grpc",
    path = "dep/grpc",
    build_file = "3rdparty/grpc.BUILD",
)
