#ifndef _SEGMENT_TREE_H_
#define _SEGMENT_TREE_H_

#include <iostream>

namespace mrroot501 {

template <typename T> class SegmentTree {
public:
    std::vector<T> arr;
    std::vector<T> nodes;
    int arrSize;
    SegmentTree();
};

template <typename T>
class SumSegmentTree: public SegmentTree<T> {
public:
    SumSegmentTree();
    SumSegmentTree(std::vector<T> arr);
    void build(int nodeIndex, int left, int right);
    void update(int index, T value, int nodeIndex, int left, int right);
    int queryRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight);
};

template <typename T>
class MinSegmentTree: public SegmentTree<T> {
public:
    MinSegmentTree();
    MinSegmentTree(std::vector<T> arr);
    void update(int index, T value, int nodeIndex, int left, int right);
    int queryRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight);
};

template <typename T>
class MaxSegmentTree: public SegmentTree<T> {
public:
    MaxSegmentTree();
    MaxSegmentTree(std::vector<T> arr);
    void update(int index, T value, int nodeIndex, int left, int right);
    int queryRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight);
};

} // namespace mrroot501

#endif // _SEGMENT_TREE_H_
