#ifndef _BINARYTREE_
#define _BINARYTREE_

#include <iostream>
using namespace std;

namespace mrroot501 {
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {};
    TreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename T, class Node>
class BinaryTree{
public:
    Node *root;
    BinaryTree() {}
    BinaryTree(T data) {
        this->root = new Node(data);
    }
    Node* insert(Node *parent, T data) {
        if(parent == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if(data <= parent->data){
                cur = insert(parent->left, data);
                parent->left = cur;
            }
            else{
                cur = insert(parent->right, data);
                parent->right = cur;
            }

            return parent;
        }
    }

    void deleteNode(Node *parent, T data) {
        int a = 0;
    }

    void preOrder(Node *parent) {
        if (parent == NULL) {
            return;
        } 

        cout << parent ->data << "\n";
        preOrder(parent->left);
        preOrder(parent->right);
    }

    void postOrder(Node *parent) {
        if (parent == NULL) {
            return;
        } 
        
        postOrder(parent->left);
        postOrder(parent->right);
        cout << parent->data << "\n";
    }

    void inOrder(Node *parent) {
        if (parent == NULL) {
            return;
        } 
        
        inOrder(parent->left);
        cout << parent->data << "\n";
        inOrder(parent->right);
    }

    void levelOrder(){
        queue<Node*> q;
        Node* n = this->root;
        if (n == NULL)
            return;
        q.push(n);
        while (!q.empty()) {
            cout << n->data << "\n";

            if (n->left != NULL) q.push(n->left);
            if (n->right != NULL) q.push(n->right);
            
            q.pop();
            if(!q.empty())
                n = q.front();      
        }
    }

    Node* find(Node *parent, T data) {
        if (data == parent->data) {
            return parent;
        } else if (data < parent->data && parent->left != NULL) {
            return find(parent->left, data);
        } else if (data > parent->data && parent->right != NULL) {
            return find(parent->right, data);
        } else {
            return NULL;
        }
    }

    int getHeight(Node *parent){
        if(parent == NULL) return 0;
        
        int h_l = getHeight(parent->left);
        int h_r = getHeight(parent->right);
        return ( 1 + ( (h_r > h_l) ? h_r : h_l ) );
    }
};

} // namespace mrroot501

#endif
