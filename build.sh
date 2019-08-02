bazel build //src:greeter_server \
    --incompatible_depset_is_not_iterable=false \
    --jobs 8