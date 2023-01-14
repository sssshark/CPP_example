cc_binary(
    name = "client_example",
    srcs = ["client.cc"],
    # defines = ["BAZEL_BUILD"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "//proto:helloworld_cc_grpc",
    ],
)