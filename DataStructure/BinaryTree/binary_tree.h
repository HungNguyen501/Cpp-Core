#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

namespace mrroot501 {
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(T data);
};

template <typename T>
class BinaryTree{
public:
    TreeNode<T> *root;
    BinaryTree();
    BinaryTree(T data);
    TreeNode<T>* insert(TreeNode<T> *parent, T data);
    TreeNode<T>* deleteNode(TreeNode<T>* current, T value);
    void preOrder(TreeNode<T>* parent);
    void postOrder(TreeNode<T> *parent);
    void inOrder(TreeNode<T> *parent);
    void levelOrder();
    TreeNode<T>* find(TreeNode<T>* parent, T data);
    int getHeight(TreeNode<T>* parent);
};

} // namespace mrroot501

#endif // _BINARY_TREE_H_
