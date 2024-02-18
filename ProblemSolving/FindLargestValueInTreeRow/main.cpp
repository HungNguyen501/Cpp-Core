#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "../../DataStructure/BinaryTree/BinaryTree.h"
using namespace std;

void findLargestValueInTreeRow(BinaryTree btree) {
    vector<int> result;
    queue<Node *> row;
    row.push(btree.root);
    while (!row.empty()) {
        int max = row.front()->data;
        int length = row.size();
        for (int i = 0; i < length; i++) {
            Node *node = row.front();
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
    read.open("input.txt");
    // Initial binary tree
    int n, data;
    read >> n;
    read >> data;
    BinaryTree btree(data);
    for (int i = 0; i < n - 1; i++) {
        read >> data;
        btree.root = btree.insert(btree.root, data);
    }
    findLargestValueInTreeRow(btree);

    return 0;
}

