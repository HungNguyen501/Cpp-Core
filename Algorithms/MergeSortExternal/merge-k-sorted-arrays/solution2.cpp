#include <iostream>

using namespace std;

#define array_size 4

struct MinHeapNode {
    int data;
    int index;
    int nextIndex;
};

void swap(MinHeapNode *x, MinHeapNode *y) {
    MinHeapNode temp  = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
    MinHeapNode *pointer; // Pointer to array of elements in min heap
    int heap_size;

public:
    MinHeap(MinHeapNode arr[], int _heap_size) {
        pointer = arr;
        heap_size = _heap_size;

        int i = (heap_size - 1)/2;

        while(i >= 0) {
            minheadify(i);
            i--;
        }
    }

    int indexLeftChild(int i) {
        return (2*i+1);
    }

    int indexRightChild(int i) {
        return (2*i+2);
    }

    MinHeapNode getRoot() {
        return pointer[0];
    }

    void minheadify(int i) {
        int l = indexLeftChild(i);
        int r = indexRightChild(i);
        int smallest = i;

        // Get minimum elements from node, left child's node and right child's node
        if (l < heap_size && pointer[l].data < pointer[i].data) {
            smallest = l;
        } 
        
        if (r < heap_size && pointer[r].data < pointer[smallest].data) {
            smallest = r;
        } 
        
        // Store smallest number to node
        if (smallest != i) {
            swap(&pointer[i], &pointer[smallest]);
            minheadify(smallest);
        }

    }

    void replaceRoot(MinHeapNode new_root) {
        // Replace by new_root
        pointer[0] = new_root;

        // Re-sort MinHeap
        minheadify(0);
    }


};

int *mergeKArrays(int arr[][array_size], 
                int num_size) 
{
    // Store output array
    int *output = new int[num_size*array_size];

    // Create an heap node array containing first element of arrays in arr
    MinHeapNode heap_arr[num_size];
    for (int i = 0; i < num_size; i++) {
        heap_arr[i].data = arr[i][0];
        heap_arr[i].index = i;
        heap_arr[i].nextIndex = 1;
    }

    // Create a new MinHeap
    MinHeap *minHeap = new MinHeap(heap_arr, num_size);

    for (int i = 0; i < num_size*array_size; i++) {
        // Get the minimum element of minHeap and store it in output
        MinHeapNode root = minHeap->getRoot();
        output[i] = root.data;

        if (root.nextIndex < array_size) {
            root.data = arr[root.index][root.nextIndex];
            root.nextIndex++;
        } else {
            root.data = INT32_MAX;
        }

        // Replace root of minHeap with the next element of array
        minHeap->replaceRoot(root);

    }

    return output;

}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[][array_size] = {{2, 6, 12, 34},
                {1, 9, 20, 1000},
                {23, 34, 90, 2000}};

    int num_size = sizeof(arr)/sizeof(arr[0]);

    int *output = mergeKArrays(arr, num_size);

    printArray(output, num_size*array_size);

    system("Pause");
    return 0;
}