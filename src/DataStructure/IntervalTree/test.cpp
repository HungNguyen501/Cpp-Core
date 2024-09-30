#include <iostream>
#include <array>
#include <gtest/gtest.h>
#include "interval_tree.h"
using namespace std;

TEST(TestIntervalTree, testTC1) {
    int inputs[][2] = {{15, 20}, {10, 12}, {17, 19}, {5, 7}, {12, 15}, {30, 40}};
    bool expectedInsertions[] = {true, true, false, true, false, true};
    mrroot501::IntervalTree<int> tree;
    for (int i = 0; i < int(sizeof(expectedInsertions) / sizeof(expectedInsertions[0])); i++) {
        EXPECT_EQ(tree.inserted(inputs[i][0], inputs[i][1]), expectedInsertions[i]);
    }
    tree.traversalInorder();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
