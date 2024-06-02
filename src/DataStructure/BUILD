# load("@buildifier_prebuilt//:rules.bzl", "buildifier")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

# Libraries
cc_library(
    name = "binary_tree_lib",
    srcs = ["BinaryTree/binary_tree.cpp"],
    hdrs = ["BinaryTree/binary_tree.h"],
)

cc_library(
    name = "stack_lib",
    srcs = ["Stack/stack.cpp"],
    hdrs = ["Stack/stack.h"],
)

# Excutable binaries
# cc_binary(
#     name = "binary_tree",
#     srcs = ["BinaryTree/main.cpp"],
#     deps = [
#         ":binary_tree_lib",
#         "@gtest",
#         "@gtest//:gtest_main",
#     ],
# )

# Tests
cc_test(
    name = "binary_tree_test",
    timeout="short",
    srcs = ["BinaryTree/main.cpp"],
    deps = [
        ":binary_tree_lib",
        "//src/ProblemSolving:find_largest_value_in_tree_row_test",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "stack_test",
    timeout="short",
    srcs = ["Stack/main.cpp"],
    deps = [
        ":stack_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)