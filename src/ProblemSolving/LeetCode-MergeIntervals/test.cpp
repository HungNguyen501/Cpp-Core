#include <iostream>
#include <vector>
#include <string>
#include "header.h"
#include <gtest/gtest.h>

TEST(TestMergeIntervals, tc1) {
    std::vector<std::vector<std::vector<int>>> input = {
        {{15, 18},{1, 3}, {8, 10}, {2, 6}},
        {{1, 4}, {4, 5}}
    };
    std::vector<std::vector<std::vector<int>>> actuals = {
        {{1, 6}, {8, 10}, {15, 18}},
        {{1, 5}}
    };
    // Run comparisons
    for (int i = 0; i < input.size(); i++) {
        EXPECT_EQ(merge(input[i]), actuals[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
