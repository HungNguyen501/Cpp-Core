#include <iostream>
#include <fstream>
#include <tuple>
#include "merge_sort.h"
using namespace std;

/*
    MergeSort: https://www.programiz.com/dsa/merge-sort
    Space complexity: O(n)
    Time complexity
        Best case: O(n*log n)
        Worst case: O(n*log n)
        Average case: O(n*log n)

*/

int main() {
    ifstream read;
    read.open("./input.txt");

    int testcase;
    read >> testcase;
    for (int tc = 0; tc < testcase; tc++) {
        int n;
        int *a = new int[100009];
        read >> n;
        for (int i = 0; i < n; i++)
            read >> a[i];
        mrroot501::mergeSort(a, 0, n - 1);
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
