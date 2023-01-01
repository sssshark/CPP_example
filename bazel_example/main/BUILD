cc_binary(
    name = "bazel_example",
    srcs = ["main.cpp"],
    deps = [
        "//module:add_func",
        "@sub_bazel_program//:multiply_func",
        "@sub_cmake_program//:division_func",
        "@glog",
    ],
)
