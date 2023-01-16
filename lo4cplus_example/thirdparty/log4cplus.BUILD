
cc_library(
    name = "log4cplus",
    srcs = ["src/liblog4cplus.so.3"],
    hdrs = glob([
        "include/log4cplus/*/*.h*"
    ]) + glob([
        "include/log4cplus/*.h*"
    ]), 
    includes = [
        "include", 
        # "external/log4cplus/include",
    ],

    visibility = ["//visibility:public"],
)