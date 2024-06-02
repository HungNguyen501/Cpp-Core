#include <iostream>

namespace mrroot501 {

template<typename T>
class HeapNode {
public:
    T data;
    int index;
    HeapNode() {
        // Default contructor
    }
    HeapNode(T data, int index) {
        this->data = data;
        this->index = index;
    }
    HeapNode(T data) {
        this->data = data;
        this->index = -1;
    }
};

template<typename T>
class HeapTree {
public:
    HeapNode<T> *pointer;
    int size;
    virtual void heapify(int n, int rootElement) = 0;
    void heapSort() {
        for (int i = this->size - 1; i >= 0; i--) {
            std::swap(this->pointer[0], this->pointer[i]); // Move root node of heap tree to right side of array as an elemination
            heapify(i, 0); // Heapify remaining tree
        }
    }
    void updateRootNode(HeapNode<T> newRootNode) {
        pointer[0] = newRootNode;
        heapify(this->size, 0);
    }
};

template<typename T>
class MaxHeap: public HeapTree<T> {
public:
    MaxHeap() {
        // Default constructor
    }
    MaxHeap(HeapNode<T> arr[], int size) {
        this->pointer = arr;
        this->size = size;
        // Build first heap tree to gain actual the root from (n/2-1)-th node that is deepest node having child node
        for (int i = this->size / 2 - 1; i >= 0; i--) {
            heapify(this->size, i);
        }
    }
    int getSize() {
        return this->size;
    }
    HeapNode<T> *getPointer() {
        return this->pointer;
    }
    HeapNode<T> getRoot() {
        return this->pointer[0];
    }
    void heapify(int n, int rootElementIndex) {
        int largestElementIndex = rootElementIndex;
        int leftChildIndex = 2 * rootElementIndex + 1;
        int rightChildIndex = 2 * rootElementIndex + 2;
        if (leftChildIndex < n && this->pointer[largestElementIndex].data < this->pointer[leftChildIndex].data) {
            largestElementIndex = leftChildIndex;
        }
        if (rightChildIndex < n && this->pointer[largestElementIndex].data < this->pointer[rightChildIndex].data) {
            largestElementIndex = rightChildIndex;
        }
        if (rootElementIndex != largestElementIndex) {
            std::swap(this->pointer[rootElementIndex], this->pointer[largestElementIndex]);
            heapify(n, largestElementIndex);
        }
    }
};

template<typename T>
class MinHeap: public HeapTree<T> {
public:
    MinHeap() {
        // Default constructor
    }
    MinHeap(HeapNode<T> arr[], int size) {
        this->pointer = arr;
        this->size = size;
        // Build first heap tree to gain the actual root from (n/2-1)-th node that is deepest node having child node
        for (int i = this->size / 2 - 1; i >= 0; i--) {
            heapify(this->size, i);
        }
    }
    HeapNode<T> getRoot() {
        return this->pointer[0];
    }
    int getSize() {
        return this->size;
    }
    HeapNode<T> *getPointer() {
        return this->pointer;
    }
    void heapify(int n, int rootElementIndex) {
        int leftChildIndex = 2 * rootElementIndex + 1;
        int rightChildIndex = 2 * rootElementIndex + 2;
        int smallestElementIndex = rootElementIndex;
        if (leftChildIndex < n && this->pointer[leftChildIndex].data < this->pointer[rootElementIndex].data) {
            smallestElementIndex = leftChildIndex;
        }
        if (rightChildIndex < n && this->pointer[rightChildIndex].data < this->pointer[smallestElementIndex].data) {
            smallestElementIndex = rightChildIndex;
        }
        if (smallestElementIndex != rootElementIndex) {
            std::swap(this->pointer[rootElementIndex], this->pointer[smallestElementIndex]);
            heapify(n, smallestElementIndex);
        }
    }
};

template class HeapNode<int>;
template class HeapTree<int>;
template class MaxHeap<int>;
template class MinHeap<int>;

} // mrroot501