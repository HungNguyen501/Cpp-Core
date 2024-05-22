#include <gtest/gtest.h>
#include "merge_sort.h"

TEST(TestMergeSort, tc1) {
    int a[] = {1, 1, 1, 2, 2};
    mrroot501::mergeSort(a, 0, sizeof(a) / sizeof(int) - 1);
    std::string expect1 = "";
    for (int i : a) {
        expect1 += (std::to_string(i) + " ");
    }
    EXPECT_EQ(expect1, "1 1 1 2 2 ");
}

TEST(TestMergeSort, tc2) {
    float a[] = {2, 1, 3, 1, 2};
    mrroot501::mergeSort(a, 0, sizeof(a) / sizeof(float) - 1);
    std::string expect1 = "";
    for (int i : a) {
        expect1 += (std::to_string(i) + " ");
    }
    EXPECT_EQ(expect1, "1 1 2 2 3 ");
}

TEST(TestMergeSort, tc3) {
    long a[] = {816783332, 961989300, 1897270484, 1587833932, 2093097502, 760094607, 1677327493, 825340682, 903966401, 1663982729};
    mrroot501::mergeSort(a, 0, sizeof(a) / sizeof(long) - 1);
    std::string expect1 = "";
    for (int i : a) {
        expect1 += (std::to_string(i) + " ");
    }
    EXPECT_EQ(expect1, "760094607 816783332 825340682 903966401 961989300 1587833932 1663982729 1677327493 1897270484 2093097502 ");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
