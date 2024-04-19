#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <tuple>
#include "BinaryTree.h"
#include "../../Common/UnitTests.h"
using namespace std;
using namespace mrroot501;

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
    ifstream input;
    int n;
    int data;
    input.open("BinaryTree/input.txt");
    input >> n >> data;
    BinaryTree<int> btree(data);
    for (int i = 0; i < n - 1; i++) {
        input >> data;
        btree.root = btree.insert(btree.root, data);
    }
    runTest<int>(btree.getHeight(btree.root), 4);
    runTest<int>(btree.find(btree.root, 6)->data, 6);
    runTest<TreeNode<int>*>(btree.find(btree.root, 8), NULL);
    // btree.levelOrder();
    TreeNode<int>* temp = btree.deleteNode(btree.root, 5);
    btree.levelOrder();
    
    return 0;
}