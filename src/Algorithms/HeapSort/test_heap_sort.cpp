#include <gtest/gtest.h>
#include "heap_sort.h"

TEST(TestHeapSort, TestMinHeap) {
    int arr[] = {9, 7, 11, 32, 45, 0, 1, 27, 28, 45, 9};
    int n= sizeof(arr) / sizeof(int);
    mrroot501::HeapNode<int> *heapTree = new mrroot501::HeapNode<int>[n];
    for (int i = 0; i < n; i++) {
        heapTree[i] = arr[i];
    }
    std::string expect = "";
    mrroot501::MinHeap<int> *minHeap = new mrroot501::MinHeap<int>(heapTree, n);
    minHeap->heapSort();
    for (int i = 0; i < minHeap->getSize(); i++) {
        expect += (std::to_string(minHeap->getPointer()[i].data) + " ");
    }
    EXPECT_EQ(minHeap->getSize(), 11);
    EXPECT_EQ(expect, "45 45 32 28 27 11 9 9 7 1 0 ");
    delete minHeap;
    delete [] heapTree;
}

TEST(TestHeapSort, TestMaxHeap) {
    int arr[] = {9, 7, 11, 32, 45, 0, 1, 27, 28, 9};
    int n = sizeof(arr) / sizeof(int);
    mrroot501::HeapNode<int> *heapTree = new mrroot501::HeapNode<int>[n];
    for (int i = 0; i < n; i++) {
        heapTree[i] = arr[i];
    }
    std::string expect = "";
    mrroot501::MaxHeap<int> *maxHeap = new mrroot501::MaxHeap<int>(heapTree, n);
    maxHeap->heapSort();
    for (int i = 0; i < maxHeap->getSize(); i++) {
        expect += (std::to_string(maxHeap->getPointer()[i].data) + " ");
    }
    EXPECT_EQ(maxHeap->getSize(), 10);
    EXPECT_EQ(expect, "0 1 7 9 9 11 27 28 32 45 ");
    maxHeap = NULL;
    heapTree = NULL;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
