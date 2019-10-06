filegroup(
    name = "image_classifier_data",
    srcs = glob([
        "*.pth",
        "*.txt",
    ]),
	visibility = [
        "//src/service:__pkg__",
        "//src/engines/specific:__pkg__"
    ],
)