#include <iostream>
#include <string>
#include <fstream>
#include "../HeapSort/heap_sort.h"
#include "../MergeSort/merge_sort.h"
using namespace std;

string DATA_PATH = "Algorithms/MergeSortExternal/data/";
string INPUT_FILE = DATA_PATH + "input.txt";
string OUTPUT_FILE = DATA_PATH + "output.txt";
string PARTITION_FILE_FORMAT = DATA_PATH + "partition=%d.txt";

/* Split large input_file , sort and save to multiple output_files
*/
void dumpSortedSmallFiles(int numPartitions, int chunkSize) {
    ifstream finput(INPUT_FILE);
    ofstream foutputs[numPartitions];

    for (int i = 0; i < numPartitions; i++) {
        char outputFile[100];
        snprintf(outputFile, sizeof(outputFile), PARTITION_FILE_FORMAT.c_str(), i);
        foutputs[i].open(outputFile);
    }
    // Allocate a dynamic array large enough to accomodate runs of size chunk size
    int *arr = (int*)malloc(chunkSize * sizeof(int));
    int item, count = 0, countFiles = 0;
    while (finput >> item) {
        arr[count] = item;
        count++;
        if (count == chunkSize) {
            mrroot501::mergeSort(arr, 0, count - 1);
            for (int j = 0; j < count; j++) {
                foutputs[countFiles] << arr[j] << " ";
            }
            count = 0;
            countFiles++;
        }
    }
    if (count > 0) {
        mrroot501::mergeSort(arr, 0, count -1 );
        for (int j = 0; j < count; j++) {
            foutputs[countFiles] << arr[j] << " ";
        }
    }
    finput.close();
    for (int i = 0; i < numPartitions; i++) {
        foutputs[i].close();
    }

}

/* Merge k sorted files
*/
void mergeFiles(int numPartitions) {
    ifstream finputs[numPartitions];
    ofstream foutput(OUTPUT_FILE);
    mrroot501::HeapNode<int> *heapNodeArr = new mrroot501::HeapNode<int>[numPartitions];
    // Open all partitioned files and fill up heapNodeArr
    for (int i = 0; i < numPartitions; i++) {
        char inputFile[100];
        snprintf(inputFile, sizeof(inputFile), PARTITION_FILE_FORMAT.c_str(), i);
        finputs[i].open(inputFile);
        finputs[i] >> heapNodeArr[i].data;
        heapNodeArr[i].index = i;
    }
    // Create MinHeap
    mrroot501::MinHeap<int> minHeap = mrroot501::MinHeap<int>(heapNodeArr, numPartitions);
    int count = 0;
    while(count < numPartitions) {
        int fileIndex = minHeap.getPointer()[0].index;
        // Save the root data (minimum element) of MinHeap to output_file
        foutput << minHeap.getPointer()[0].data << " ";
        int nextItem;
        finputs[fileIndex] >> nextItem;
        minHeap.getPointer()[0].data = nextItem;
        // Case that pointer goes to end of file
        if (finputs[fileIndex].fail()) {
            minHeap.getPointer()[0].data = INT32_MAX;
            finputs[fileIndex].close();
            count++;
        }
        // heapify MinHeap to gain actual root after root is updated by new value
        minHeap.heapify(minHeap.getSize(), 0);
    }
    foutput.close();
}

int main() {
    string command = "rm -rf " + DATA_PATH + "*.txt"; // Generate a command to erase data folder
    system(command.c_str());
    int numElements = 111;
    int chunkSize = 7, numPartitions = numElements / chunkSize + (numElements%chunkSize > 0);
    ofstream fo(INPUT_FILE);
    srand(time(NULL));
    for (int i = 0; i < numElements; i++) {
        fo << rand() / 10000000 << " ";
    }
    fo.close();
    dumpSortedSmallFiles(numPartitions, chunkSize);
    mergeFiles(numPartitions);
    return 0;
}