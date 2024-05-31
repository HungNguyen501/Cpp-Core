# load("@buildifier_prebuilt//:rules.bzl", "buildifier")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

# Libraries
cc_library(
    name = "heap_sort_lib",
    srcs = ["HeapSort/heap_sort.cpp"],
    hdrs = ["HeapSort/heap_sort.h"],
)

cc_library(
    name = "merge_sort_lib",
    srcs = ["MergeSort/merge_sort.cpp"],
    hdrs = ["MergeSort/merge_sort.h"],
)

cc_library(
    name = "quick_sort_lib",
    srcs = ["QuickSort/quick_sort.cpp"],
    hdrs = ["QuickSort/quick_sort.h"],
)

# Excutable binaries
cc_binary(
    name = "heap_sort",
    srcs = ["HeapSort/main.cpp"],
    deps = [
        ":heap_sort_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "merge_sort",
    srcs = ["MergeSort/main.cpp"],
    deps = [
        ":merge_sort_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "quick_sort",
    srcs = ["QuickSort/main.cpp"],
    deps = [
        ":quick_sort_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "merge_sort_external",
    srcs = ["MergeSortExternal/main.cpp"],
    deps = [
        ":merge_sort_lib",
        ":heap_sort_lib",
    ],
)

# Tests
cc_test(
    name = "heap_sort_test",
    srcs = ["HeapSort/test_heap_sort.cpp"],
    deps = [
        ":heap_sort_lib",
        ":heap_sort",
        ":merge_sort_external",
        "//src/ProblemSolving:merge_k_sorted_arrays_test",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "merge_sort_test",
    srcs = ["MergeSort/test_merge_sort.cpp"],
    deps = [
        ":merge_sort_lib",
        ":merge_sort",
        ":merge_sort_external",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "quick_sort_test",
    srcs = ["QuickSort/test_quick_sort.cpp"],
    deps = [
        ":quick_sort_lib",
        ":quick_sort",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "merge_sort_external_test",
    srcs = ["MergeSortExternal/test_merge_sort_external.cpp"],
    deps = [
        ":merge_sort_external",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
