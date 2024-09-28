#include <iostream>
#include <vector>
#include <string>
#include "header.h"
#include <gtest/gtest.h>

TEST(TestCountConsistentStrings, tc1) {
    int tc1[] = {1, 4, 2, 5, 0};
    int tc2[] = {2, 3, 4, 1, 4, 5};
    int tc3[] = {1, 2, 3};
    int expected[] = {2, 1, -1};
    EXPECT_EQ(findElement(tc1, sizeof(tc1) / sizeof(int)), expected[0]);
    EXPECT_EQ(findElement(tc2, sizeof(tc2) / sizeof(int)), expected[1]);
    EXPECT_EQ(findElement(tc3, sizeof(tc3) / sizeof(int)), expected[2]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
