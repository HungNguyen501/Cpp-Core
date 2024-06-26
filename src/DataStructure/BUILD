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

cc_library(
    name = "queue_lib",
    srcs = ["Queue/queue.cpp", "Queue/message.cpp",],
    hdrs = ["Queue/queue.h", "Queue/message.h",],
)

cc_library(
    name = "doubly_linked_list_lib",
    srcs = ["LinkedList/doubly_linked_list.cpp", "LinkedList/ll_node.cpp"],
    hdrs = ["LinkedList/doubly_linked_list.h", "LinkedList/ll_node.h"],
)

cc_library(
    name = "linked_list_lib",
    srcs = ["LinkedList/linked_list.cpp", "LinkedList/ll_node.cpp"],
    hdrs = ["LinkedList/linked_list.h", "LinkedList/ll_node.h"],
)

cc_library(
    name = "message_queue_lib",
    srcs = ["Queue/message.cpp", "Queue/queue.cpp", "MessageQueue/message_queue.cpp",],
    hdrs = ["Queue/message.h", "Queue/queue.h", "MessageQueue/message_queue.h",],
)

# Excutable binaries
# cc_binary(
#     name = "doubly_linked_list_main",
#     srcs = ["LinkedList/test_doubly_linked_list.cpp"],
#     deps = [
#         ":doubly_linked_list_lib",
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

cc_test(
    name = "queue_test",
    timeout="short",
    srcs = ["Queue/queue_test.cpp"],
    deps = [
        ":queue_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "doubly_linked_list_test",
    timeout="short",
    srcs = ["LinkedList/test_doubly_linked_list.cpp"],
    deps = [
        ":doubly_linked_list_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "linked_list_test",
    timeout="short",
    srcs = ["LinkedList/test_linked_list.cpp"],
    deps = [
        ":linked_list_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "message_queue_test",
    timeout="short",
    srcs = ["MessageQueue/message_queue_test.cpp"],
    deps = [
        ":message_queue_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
