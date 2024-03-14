#ifndef _BINARYTREE_
#define _BINARYTREE_

#include <iostream>

namespace mrroot501 {
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        this->data = NULL;
        this->left = NULL;
        this->right = NULL;
    };
    TreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename T>
class BinaryTree{
public:
    TreeNode<T>* root;
    BinaryTree() {}
    BinaryTree(T data) {
        this->root = new TreeNode<T>(data);
    }
    TreeNode<T>* insert(TreeNode<T> *parent, T data) {
        if(parent == NULL) {
            return new TreeNode<T>(data);
        }
        else {
            TreeNode<T>* cur;
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

    TreeNode<T>* deleteNode(TreeNode<T>* current, T value) {
        if (value > current->data && current->right != NULL) {
            current->right = deleteNode(current->right, value);
        } else if (value < current->data && current->left != NULL) {
            current->left = deleteNode(current->left, value);
        } else if (current->data == value) {
            std::cout << "pppp\n";
            // Case: node has no childs
            if (current->left == NULL && current->right == NULL) {
                return NULL;
            }
            // Case: node has only one child
            if (current->left == NULL) {
                TreeNode<T>* rightFollower = current->right;
                std::cout << "aaa\n";
                // delete current;
                return rightFollower;
            } else if (current->right == NULL) {
                TreeNode<T>* leftFollower = current->left;
                std::cout << "bbb\n";
                // delete current;
                return leftFollower;
            }
            // Case: node has both 2 childs
            TreeNode<T>* successor = current;
            TreeNode<T>* descendant = successor->right;
            while (descendant->left != NULL) {
                successor = descendant;
                descendant = successor->left;
            }
            if (successor != current) {
                successor->left = descendant->right;
            } else {
                successor->right = descendant->right;
            }
            current->data = descendant->data;
            delete descendant;
        }
        return current;
    }

    void preOrder(TreeNode<T>* parent) {
        if (parent == NULL) {
            return;
        } 

        std::cout << parent ->data << "\n";
        preOrder(parent->left);
        preOrder(parent->right);
    }

    void postOrder(TreeNode<T> *parent) {
        if (parent == NULL) {
            return;
        } 
        
        postOrder(parent->left);
        postOrder(parent->right);
        std::cout << parent->data << "\n";
    }

    void inOrder(TreeNode<T> *parent) {
        if (parent == NULL) {
            return;
        } 
        
        inOrder(parent->left);
        std::cout << parent->data << "\n";
        inOrder(parent->right);
    }

    void levelOrder(){
        std::queue<TreeNode<T>*> tempQueue;
        TreeNode<T>* node = this->root;
        if (node == NULL) {return;}
        tempQueue.push(node);
        while (!tempQueue.empty()) {
            int size = tempQueue.size();
            for (int i = 0; i < size; i++) {
                node = tempQueue.front();
                std::cout << node->data << " ";
                if (node->left != NULL) tempQueue.push(node->left);
                if (node->right != NULL) tempQueue.push(node->right);
                tempQueue.pop();
            }
            std::cout << "\n";
        }
    }

    TreeNode<T>* find(TreeNode<T>* parent, T data) {
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

    int getHeight(TreeNode<T>* parent){
        if(parent == NULL) return 0;
        
        int h_l = getHeight(parent->left);
        int h_r = getHeight(parent->right);
        return ( 1 + ( (h_r > h_l) ? h_r : h_l ) );
    }
};

} // namespace mrroot501

#endif
