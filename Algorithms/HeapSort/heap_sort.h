#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

namespace mrroot501 {

template<typename T> class HeapNode{
public:
    T data;
    int index;
    HeapNode();
    HeapNode(T data, int index);
    HeapNode(T data);
};

template<typename T> class HeapTree{
public:
    void heapSort();
};

template<typename T> class MaxHeap: public HeapTree<T>{
public:
    MaxHeap();
    MaxHeap(HeapNode<T> arr[], int size);
    int getSize();
    HeapNode<T> *getPointer();
    void heapify(int n, int rootElementIndex);
};

template<typename T> class MinHeap: public HeapTree<T>{
public:
    MinHeap();
    MinHeap(HeapNode<T> arr[], int size);
    int getSize();
    HeapNode<T> *getPointer();
    void heapify(int n, int rootElementIndex);
};

} // namespace mrroot501

#endif // _HEAP_SORT_H_