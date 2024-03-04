#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "../../DataStructure/BinaryTree/BinaryTree.h"
using namespace mrroot501;

void findLargestValueInTreeRow(BinaryTree<int, TreeNode<int>> btree) {
    vector<int> result;
    queue<TreeNode<int> *> row;
    row.push(btree.root);
    while (!row.empty()) {
        int max = row.front()->data;
        int length = row.size();
        for (int i = 0; i < length; i++) {
            TreeNode<int> *node = row.front();
            row.pop();
            max = (max > node->data ? max : node->data);
            if (node->left != NULL)
                row.push(node->left);
            if (node->right != NULL)
                row.push(node->right);
        }
        result.push_back(max);
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
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

int main() {
    ifstream read;
    int n, data;
    read.open("FindLargestValueInTreeRow/input.txt");
    read >> n;
    read >> data;
    BinaryTree<int, TreeNode<int>> btree(data);
    for (int i = 0; i < n - 1; i++) {
        read >> data;
        btree.root = btree.insert(btree.root, data);
    }
    findLargestValueInTreeRow(btree);

    return 0;
}

