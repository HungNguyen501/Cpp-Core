/*
    Links:
        https://www.geeksforgeeks.org/Terval-tree/
        https://leetcode.com/problems/my-calendar-i/
        https://leetcode.com/problems/my-calendar-ii/
*/
#include <iostream>

namespace mrroot501 {

template<typename T>
class ITNode {
private:
    T from, to, max_value_in_subtree;
public:
    ITNode<T> *left, *right;
    ITNode() {
        // Default constructor
    }
    ITNode(T from, T to) {
        this->from = from;
        this->to = to;
        this->max_value_in_subtree = to;
        this->left = this->right = NULL;
    }

    T getFromValue() {
        return this->from;
    }
    T getToValue() {
        return this->to;
    }
    T getMaxValueInSubtree() {
        return this->max_value_in_subtree;
    }
    void setMaxValueInSubtree(T value) {
        this->max_value_in_subtree = value;
    }
};

template<typename T>
class IntervalTree {
private:
    ITNode<T> *root;

    bool doOverlap(ITNode<T> *node1, ITNode<T> *node2) {
        if (node1->getFromValue() > node2->getToValue() || node1->getToValue() < node2->getFromValue()) {
            return false;
        }
        return true;
    }

    ITNode<T> *insert(ITNode<T> *curNode, ITNode<T> *newNode, bool &isOverlapped) {
        if (curNode == NULL) {
            return newNode;
        }
        if (doOverlap(curNode, newNode)) {
            isOverlapped = true;
            return curNode;
        }
        if (newNode->getFromValue() > curNode->getMaxValueInSubtree() || newNode->getFromValue() >= curNode->getFromValue()) {
            curNode->right = insert(curNode->right, newNode, isOverlapped);
        } else {
            curNode->left = insert(curNode->left, newNode, isOverlapped);
        }
        if (curNode->getMaxValueInSubtree() < newNode->getMaxValueInSubtree()) {
            curNode->setMaxValueInSubtree(newNode->getMaxValueInSubtree());
        }
        return curNode;
    }

    ITNode<T> *searchOverlap(ITNode<T> *curNode, ITNode<T> *inputNode) {
        if (curNode == NULL || inputNode->getFromValue() > curNode->getMaxValueInSubtree()) return NULL;
        if (doOverlap(curNode, inputNode)) return curNode;
        ITNode<T> *leftResult = searchOverlap(curNode->left, inputNode);
        if (leftResult != NULL) return leftResult;
        ITNode<T> *rightResult = searchOverlap(curNode->right, inputNode);
        if (rightResult != NULL) return rightResult;
        return NULL;
    }

    void inorder(ITNode<T> *curNode) {
        if (curNode == NULL) return;
        inorder(curNode->left);
        std::cout << curNode->getFromValue() << "->" << curNode->getToValue() << ", " << curNode->getMaxValueInSubtree() << "\n";
        inorder(curNode->right);
    }

public:
    IntervalTree() {
        // Default contructor
        this->root = NULL;
    }

    IntervalTree(ITNode<T> *node) {
        this->root = node;
    }

    void setRootNode(ITNode<T> *node) {
        this->root = node;
    }

    ITNode<T> *getRootNode() {
        return this->root;
    }

    bool inserted(T start, T end) {
        bool isOverlapped = false;
        setRootNode(insert(getRootNode(), new ITNode<T>(start, end), isOverlapped));
        return !isOverlapped;
    }

    ITNode<T> *findOverlapping(ITNode<T> *inputNode) {
        return searchOverlap(getRootNode(), inputNode);
    }

    void traversalInorder() {
        inorder(getRootNode());
    }
};

template class ITNode<int>;
template class IntervalTree<int>;

} // namespace mrroot501
