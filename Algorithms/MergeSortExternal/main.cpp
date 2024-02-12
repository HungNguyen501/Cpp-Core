#include <iostream>
#include <string>
#include <fstream>
#include "MinHeap.h"
#include "MergeSort.h"
using namespace std;

FILE *openFile(char *file_name, char *mode) {
    FILE *fp = fopen(file_name, mode);
    if (fp == NULL) {
        perror("Error while opening file.\n");
        exit(EXIT_FAILURE);
    }

    return fp;
}

// Split large input_file , sort and save to multiple output_files
void createInitialRun(char *input_file,
                    int run_size, 
                    int num_ways)
{
    // Read input file
    FILE *fi = openFile(input_file, "r");

    // Initial output files
    FILE *fo[num_ways];
    char output_file[16];

    for (int i = 0; i < num_ways; i++) {
        // Convert i to output_file (int to char array)
        snprintf(output_file, sizeof(output_file), "partition=%d.txt", i);

        fo[i] = openFile(output_file, "w");
    }
    // Allocate a dynamic array large enough to accomodate runs of size run_size
    int *arr = (int*)malloc(run_size*sizeof(int));

    bool more_input = true;
    int next_output_file = 0;

    int i;
    while(more_input) {
        // Write run_size elements into arr from input_file
        for (i = 0; i < run_size; i++) {
            if (fscanf(fi, "%d ", &arr[i]) != 1) { // Function fscanf return number of arguments that are read
                more_input = false;
                break;
            }
        }

        // Sort array using merge sort
        mergeSort(arr, 0, i-1);

        // Write score to output_file
        for (int j = 0; j < i; j++) {
            fprintf(fo[next_output_file], "%d ", arr[j]);
        }

        next_output_file++;
    }

    // Close input and output files
    fclose(fi);

    for (int i = 0; i < num_ways; i++) {
        fclose(fo[i]);
    }

}

// Merge k sorted files
void mergeFiles(char *output_file, 
                int num_files) 
{
    FILE *fi[num_files];

    // Read all partitioned files
    for (int i = 0; i < num_files; i++) {
        char file_name[16];
       // Convert i to file_name (int to char array)
        snprintf(file_name, sizeof(file_name), "MergeSortExternal/partition=%d.txt", i);

        fi[i] = openFile(file_name, "r");
    }

    // Write to output_file
    FILE *fo = openFile(output_file, "w");

    // Creat MinHeapNode array
    MinHeapNode *heap_arr = new MinHeapNode[num_files];    
    int i;
    for (i = 0; i < num_files; i++) {
        // Get the minimum elements of all partition files to heap_arr
        if (fscanf(fi[i], "%d ", &heap_arr[i].data) != 1) { // function fscanf return number of parameter returned
            break;
        }
        // Store index of partition file in MinHeap
        heap_arr[i].index = i;
    }

    // Create MinHeap
    MinHeap minHeap(heap_arr, i);

    int count = 0;
    while(count != i) {
        MinHeapNode root = minHeap.getRoot();
        // Save the root data (minimum element) of MinHeap to output_file
        fprintf(fo, "%d ", root.data);

        if (fscanf(fi[root.index], "%d ", &root.data) != 1) {
            root.data = INT32_MAX;
            count++;
        }

        // Replace root
        minHeap.rearrangeMinHeap(root);
    }

    // Close all input and output files
    for (int i = 0; i < num_files; i++) {
        fclose(fi[i]);
    }

    fclose(fo);

}

void externalSort(char *input_file, 
                char *output_file, 
                int num_ways, 
                int run_size)
{
    createInitialRun(input_file, run_size, num_ways);

    mergeFiles(output_file, num_ways);
}            


int main() {    
    // Partitioning input file
    int num_ways = 10;
    // Size of each partiton
    int run_size = 1000;

    char input_file[] = "MergeSortExternal/input.txt";
    char output_file[] = "MergeSortExternal/output_file.txt";

    FILE *fi = openFile(input_file, "w");
    // srand(time(NULL));

    // Generate input
    for (int i = 0; i < num_ways*run_size; i++) {
        fprintf(fi, "%d ", rand());
    }

    fclose(fi);

    // Run external sort
    externalSort(input_file, output_file, num_ways, run_size);

    return 0;
}