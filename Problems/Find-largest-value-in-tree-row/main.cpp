#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

};

class BinaryTree {
public:
    Node *root;

    BinaryTree(int data) {
        this->root = new Node(data);
    }

    Node *insertNode(Node *parent, int data) {
        if (parent == NULL) {
            return new Node(data);
        } else {
            Node *child;
            if (data < parent->data) {
                child = insertNode(parent->left, data);
                parent->left = child;
                return parent;
            }
            child = insertNode(parent->right, data);
            parent->right = child;
            return parent;
        }
    }

    void levelOrder() {
        queue<Node *> row;
        Node * node = this->root;
        row.push(node);
        while (!row.empty()) {
            cout << node->data << " ";
            if (node->left != NULL) row.push(node->left);
            if (node->right != NULL) row.push(node->right);
            row.pop();
            if (!row.empty()) node = row.front();
        }
        cout << "\n";
    }

    void findLargestValueInTreeRow() {
        vector<int> result;
        queue<Node *> row;
        row.push(this->root);
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
};

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
    read.open(".//input.txt");
    // Initial binary tree
    int n, data;
    read >> n;
    read >> data;
    BinaryTree btree = BinaryTree(data);
    for (int i = 0; i < n - 1; i++) {
        read >> data;
        btree.root = btree.insertNode(btree.root, data);
    }
    // Traverse btree by preOrder method
    btree.findLargestValueInTreeRow();

    return 0;
}

