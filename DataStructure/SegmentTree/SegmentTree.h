#ifndef _SEGMENTTREE_
#define _SEGMENTTREE_

#include <iostream>
#include <vector>
using namespace std;

namespace mrroot501 {
template <typename T>
class SegmentTree {
public:
    vector<T> arr;
    vector<T> nodes;
    int arrSize;
    SegmentTree() {
        // Default contructor
    }

    SegmentTree(vector<T> arr) {
        arrSize = arr.size();
        this->arr = arr;
        nodes.reserve(2 * arrSize + 1);
        build(0, 0, arrSize - 1);
    }

    void build(int nodeIndex, int left, int right) {
        if (left == right) {
            nodes[nodeIndex] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * nodeIndex + 1, left, mid);
        build(2 * nodeIndex + 2, mid + 1, right);
        nodes[nodeIndex] = nodes[2 * nodeIndex + 1] + nodes[2 * nodeIndex + 2];
    }

    void update(int index, T value, int nodeIndex, int left, int right) {
        if (left == right) {
            nodes[nodeIndex] += (value - arr[index]);
            arr[index] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (left <= index && index <= mid) {
            update(index, value, 2 * nodeIndex + 1, left, mid);
        } else {
            update(index, value, 2 * nodeIndex + 2, mid + 1, right);
        }
        nodes[nodeIndex] = nodes[2 * nodeIndex + 1] + nodes[2 * nodeIndex + 2];

    }

    int querySumRanges(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) return 0;
        // If query range covers the segment
        if (queryLeft <= left && right <= queryRight) {
            return nodes[nodeIndex];
        }
        // Query range is partially inside and partially outside the given range
        int mid = (left + right) / 2;
        int leftHalf = querySumRanges(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        int rightHalf = querySumRanges(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        return (leftHalf + rightHalf);
    }
};

} // namespace mrroot501

#endif
