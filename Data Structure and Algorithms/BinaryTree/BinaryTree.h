#ifndef _BINARYTREE_
#define _BINARYTREE_

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class BinaryTree{
    public:
        Node *root;

        BinaryTree() {
            // Default contructor
        }

        BinaryTree(int data) {
            this->root = new Node(data);
        }

        Node* insert(Node *parent, int data) {
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
            queue<Node *> q;
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

        int getHeight(Node *parent){
            if(parent == NULL) return 0;
            
            int h_l = getHeight(parent->left);
            int h_r = getHeight(parent->right);
            return ( 1 + ( (h_r > h_l) ? h_r : h_l ) );
        }

        Node* find(Node *parent, int data) {
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

};

#endif