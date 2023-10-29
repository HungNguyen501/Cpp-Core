#include <iostream>
#include <fstream>
#include <queue>
#include "BinaryTree.h"
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

int main() {
    ifstream input;
    input.open("input.txt");

    int n;
    int data;
    input >> n >> data;
    BinaryTree btree(data);

    for (int i = 0; i < n - 1; i++) {
        input >> data;
        btree.root = btree.insert(btree.root, data);
    }

    int heightTreeResult = btree.getHeight(btree.root);
    int expectedHeightTree = 4;
    if (heightTreeResult != expectedHeightTree) {
        cout << "Unit tests failed because height of is not " << heightTreeResult << ". It should be " << expectedHeightTree << "\n";
        return 0;
    }

    int item = 8;
    if (btree.find(btree.root, item) != NULL) {
        cout << "Unit test failed because node valued " << item << " exists in btree\n";
    }

    cout << "All test cases passed\n";
    return 0;
}