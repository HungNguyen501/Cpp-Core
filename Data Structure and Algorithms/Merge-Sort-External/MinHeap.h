#ifndef _MINHEAP_
#define _MINHEAP_

#include <iostream>

using namespace std;

struct MinHeapNode {
    int data;
    int index;
};

class MinHeap {
    MinHeapNode *pointer;
    int heap_size;
public:
    MinHeap(MinHeapNode arr[], int _heap_size) {
        pointer = arr;
        heap_size = _heap_size;

        int i = (heap_size - 1)/2;

        while(i >= 0) {
            minheapify(i);
            i--;
        }
    }

    int indexLeftChild(int i) {
        return (2*i + 1);
    }

    int indexRightChild(int i) {
        return (2*i + 2);
    }

    MinHeapNode getRoot() {
        return pointer[0];
    }

    void swap(MinHeapNode *x, MinHeapNode *y) {
        MinHeapNode temp = *x;
        *x = *y;
        *y = temp;
    }

    void minheapify(int i) {
        int left = indexLeftChild(i);
        int right = indexRightChild(i);
        int smallest = i;

        if (left < heap_size && pointer[left].data < pointer[i].data) {
            smallest = left;
        }

        if (right < heap_size && pointer[right].data < pointer[smallest].data) {
            smallest = right;
        }

        if (smallest != i) {
            swap(&pointer[i], &pointer[smallest]);
            minheapify(smallest);
        }
    }

    void rearrangeMinHeap(MinHeapNode new_root) {
        pointer[0]  = new_root;

        // Re-arrange the Min Heap
        minheapify(0);
    }

};

#endif