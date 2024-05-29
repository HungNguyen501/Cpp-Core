#include <iostream>
#include <fstream>
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
    ifstream input;
    int n;
    int data;
    input.open("DataStructure/BinaryTree/input.txt");
    input >> n >> data;
    mrroot501::BinaryTree<int> btree(data);
    for (int i = 0; i < n - 1; i++) {
        input >> data;
        btree.root = btree.insert(btree.root, data);
    }
    EXPECT_EQ(btree.getHeight(btree.root), 4);
    // EXPECT_EQ(btree.find(btree.root, 6)->data, 6);
    // EXPECT_EQ(btree.getHeight(btree.root), 4);
    // btree.levelOrder();
    // mrroot501::TreeNode<int>* temp = btree.deleteNode(btree.root, 5);
    // btree.levelOrder();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
