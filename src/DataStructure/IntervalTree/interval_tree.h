#ifndef _INTERVAL_TREE_H_
#define _INTERVAL_TREE_H_

namespace mrroot501 {

template<typename T>
class ITNode {
public:
    ITNode *left, *right;
    ITNode();
    ITNode(T from, T to);
    T getFromValue();
    T getToValue();
    T getMaxValueInSubtree();
    void setMaxValueInSubtree(T value);
};

template<typename T>
class IntervalTree {
public:
    ITNode<T> *root;
    IntervalTree();
    IntervalTree(ITNode<T> *node);
    bool inserted(T start, T end);
    ITNode<T> *findOverlapping(ITNode<T> *inputNode);
    void traversalInorder();
};

} // namespace mrroot501

#endif // _INTERVAL_TREE_H_
