#include <iostream>
#include "binary_tree.h"
#include <gtest/gtest.h>
using namespace std;

/*
                3
               / \
              2   5
             /   / \
            1   4   6
                     \
                      7
*/

TEST(TestBinaryTree, tc1) {
    int input[] = {7, 3, 5, 2, 1, 4, 6, 7};
    int n = input[0];
    mrroot501::BinaryTree<int> btree(input[1]);
    for (int i = 2; i <= n; i++) {
        btree.root = btree.insert(btree.root, input[i]);
    }
    EXPECT_EQ(btree.getHeight(btree.root), 4);
    EXPECT_EQ(btree.find(btree.root, 6)->data, 6);
    // btree.levelOrder();
    btree.deleteNode(btree.root, 6);
    // btree.levelOrder();
    EXPECT_EQ(btree.getHeight(btree.root), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
