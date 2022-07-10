#include <iostream>
#include <fstream>
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

class Solution{
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

        void preOrder(Node *root) {
            if (root == NULL) {
                return;
            } 

            cout << root ->data << endl;
            preOrder(root->left);
            preOrder(root->right);
        }

        void postOrder(Node *root) {
            if (root == NULL) {
                return;
            } 
            
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << endl;
        }

        void inOrder(Node *root) {
            if (root == NULL) {
                return;
            } 
            
            inOrder(root->left);
            cout << root->data << endl;
            inOrder(root->right);
        }

		void levelOrder(Node* root){
            queue<Node *> q;
            Node* n = root;
            if (n == NULL)
                return;
            q.push(n);
            while (!q.empty()) {
                cout << n->data << endl;

                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
                
                q.pop();
                if(!q.empty())
                    n = q.front();      
            }
        }

        int getHeight(Node* root){
            if(root == NULL) return -1;
            
            int h_l = getHeight(root->left);
            int h_r = getHeight(root->right);
            return ( 1 + ( (h_r > h_l) ? h_r : h_l ) );
        }

        Node* find(Node *root, int data) {
            if (data == root->data) {
                return root;
            } else if (data < root->data && root->left != NULL) {
                return find(root->left, data);
            } else if (data > root->data && root->right != NULL) {
                return find(root->right, data);
            } else {
                return NULL;
            }
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
    ifstream input;
    input.open("D:\\Projects\\CPP\\Data Structure and Algorithms\\Binary Tree\\input.txt");

    Solution myTree;
    Node* root = NULL;
    int n;
    int data;

    input >> n;
    for (int i = 0; i < n; i++) {
        input >> data;
        root = myTree.insert(root, data);
    }

    int height = myTree.getHeight(root);
    cout << "Height of tree: " << height << endl;

    cout << "Preorder:" << endl;
    myTree.preOrder(root);

    cout << "Postorder:" << endl;
    myTree.postOrder(root);

    cout << "Inorder:" << endl;
    myTree.inOrder(root);

    cout << "Level order:" << endl;
    myTree.levelOrder(root);

    Node* my_node = myTree.find(root, 8);

    if (my_node==NULL) {
        cout << "Not found" << endl;
    } else {
        cout << "Bingo: " << my_node << endl;
    }

    system("pause");
    return 0;
}