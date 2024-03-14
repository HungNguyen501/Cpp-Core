#ifndef _SEGMENTTREE_
#define _SEGMENTTREE_

#include <iostream>

namespace mrroot501 {

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

template <typename T>
class SegmentTree {
public:
    std::vector<T> arr;
    std::vector<T> nodes;
    int arrSize;
    SegmentTree() {
        // Default contructor
    }
    virtual void build(int nodeIndex, int left, int right) = 0;
    virtual void update(int index, T value, int nodeIndex, int left, int right) = 0;
    virtual int queryRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight) = 0;
};

template <typename T>
class SumSegmentTree: public SegmentTree<T> {
public:
    SumSegmentTree() {
        // Default constructor
    }
    SumSegmentTree(std::vector<T> arr) {
        this->arrSize = arr.size();
        this->arr = arr;
        this->nodes.reserve(1001);
        build(0, 0, this->arrSize - 1);
    }

    void build(int nodeIndex, int left, int right) {
        if (left == right) {
            this->nodes[nodeIndex] = this->arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * nodeIndex + 1, left, mid);
        build(2 * nodeIndex + 2, mid + 1, right);
        this->nodes[nodeIndex] = this->nodes[2 * nodeIndex + 1] + this->nodes[2 * nodeIndex + 2];
    }

    void update(int index, T value, int nodeIndex, int left, int right) {
        if (left == right) {
            this->nodes[nodeIndex] += (value - this->arr[index]);
            this->arr[index] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (left <= index && index <= mid) {
            update(index, value, 2 * nodeIndex + 1, left, mid);
        } else {
            update(index, value, 2 * nodeIndex + 2, mid + 1, right);
        }
        this->nodes[nodeIndex] = this->nodes[2 * nodeIndex + 1] + this->nodes[2 * nodeIndex + 2];

    }

    int queryRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) return 0;
        // If query range covers the segment
        if (queryLeft <= left && right <= queryRight) {
            return this->nodes[nodeIndex];
        }
        // Query range is partially inside and partially outside the given range
        int mid = (left + right) / 2;
        int leftHalf = queryRanges(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        int rightHalf = queryRanges(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        return (leftHalf + rightHalf);
    }
};

template <typename T>
class MinSegmentTree: public SegmentTree<T> {
public:
    MinSegmentTree() {
        // Default constructor
    }
    MinSegmentTree(std::vector<T> arr) {
        this->arrSize = arr.size();
        this->arr = arr;
        this->nodes.reserve(1001);
        build(0, 0, this->arrSize - 1);
    }

    void build(int nodeIndex, int left, int right) {
        if (left == right) {
            this->nodes[nodeIndex] = this->arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * nodeIndex + 1, left, mid);
        build(2 * nodeIndex + 2, mid + 1, right);
        this->nodes[nodeIndex] = MIN(this->nodes[2 * nodeIndex + 1], this->nodes[2 * nodeIndex + 2]);
    }

    void update(int index, T value, int nodeIndex, int left, int right) {
        if (left == right) {
            this->nodes[nodeIndex] = MIN(value, this->nodes[nodeIndex]);
            this->arr[index] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (left <= index && index <= mid) {
            update(index, value, 2 * nodeIndex + 1, left, mid);
        } else {
            update(index, value, 2 * nodeIndex + 2, mid + 1, right);
        }
        this->nodes[nodeIndex] = MIN(this->nodes[2 * nodeIndex + 1], this->nodes[2 * nodeIndex + 2]);

    }

    int queryRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) return INT32_MAX;
        // If query range covers the segment
        if (queryLeft <= left && right <= queryRight) {
            return this->nodes[nodeIndex];
        }
        // Query range is partially inside and partially outside the given range
        int mid = (left + right) / 2;
        int leftHalf = queryRanges(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        int rightHalf = queryRanges(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        return MIN(leftHalf, rightHalf);
    }
};

template <typename T>
class MaxSegmentTree: public SegmentTree<T> {
public:
    MaxSegmentTree() {
        // Default constructor
    }
    MaxSegmentTree(std::vector<T> arr) {
        this->arrSize = arr.size();
        this->arr = arr;
        this->nodes.reserve(1001);
        build(0, 0, this->arrSize - 1);
    }

    void build(int nodeIndex, int left, int right) {
        if (left == right) {
            this->nodes[nodeIndex] = this->arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * nodeIndex + 1, left, mid);
        build(2 * nodeIndex + 2, mid + 1, right);
        this->nodes[nodeIndex] = MAX(this->nodes[2 * nodeIndex + 1], this->nodes[2 * nodeIndex + 2]);
    }

    void update(int index, T value, int nodeIndex, int left, int right) {
        if (left == right) {
            this->nodes[nodeIndex] = MAX(value, this->nodes[nodeIndex]);
            this->arr[index] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (left <= index && index <= mid) {
            update(index, value, 2 * nodeIndex + 1, left, mid);
        } else {
            update(index, value, 2 * nodeIndex + 2, mid + 1, right);
        }
        this->nodes[nodeIndex] = MAX(this->nodes[2 * nodeIndex + 1], this->nodes[2 * nodeIndex + 2]);

    }

    int queryRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) return INT32_MIN;
        // If query range covers the segment
        if (queryLeft <= left && right <= queryRight) {
            return this->nodes[nodeIndex];
        }
        // Query range is partially inside and partially outside the given range
        int mid = (left + right) / 2;
        int leftHalf = queryRanges(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        int rightHalf = queryRanges(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        return MAX(leftHalf, rightHalf);
    }
};

} // namespace mrroot501

#endif
