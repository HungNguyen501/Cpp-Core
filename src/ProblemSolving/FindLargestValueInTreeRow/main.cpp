#include <iostream>
#include <queue>
#include <vector>
#include <gtest/gtest.h>
#include "../../DataStructure/BinaryTree/binary_tree.h"
using namespace std;

vector<int> findLargestValueInTreeRow(mrroot501::BinaryTree<int> btree) {
    vector<int> result;
    queue<mrroot501::TreeNode<int>*> row;
    row.push(btree.root);
    while (!row.empty()) {
        int max = row.front()->data;
        int length = row.size();
        for (int i = 0; i < length; i++) {
            mrroot501::TreeNode<int> *node = row.front();
            row.pop();
            max = (max > node->data ? max : node->data);
            if (node->left != NULL)
                row.push(node->left);
            if (node->right != NULL)
                row.push(node->right);
        }
        result.push_back(max);
    }
    return result;
}

/*
                3
               / \
              2   5
             /   / \
            1   4   6
                     \
                      7
*/

TEST(TestFindLargestValueInTreeRow, tc1) {
    int input[] = {7, 3, 5, 2, 1, 4, 6, 7};
    int t = 0;
    int n = input[t];
    t++;
    mrroot501::BinaryTree<int> btree(input[t]);
    t++;
    for (int i = 0; i < n - 1; i++) {
        btree.root = btree.insert(btree.root, input[t]);
        t++;
    }
    vector<int> actual = findLargestValueInTreeRow(btree);
    vector<int> expect = {3, 5, 6, 7};
    EXPECT_EQ(expect.size(), actual.size());
    for (int i = 0; i < actual.size(); i++) {
        EXPECT_EQ(expect[i], actual[i]);
    }   
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
