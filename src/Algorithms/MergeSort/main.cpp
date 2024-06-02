#include <iostream>
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
    int input[] = {
        3,
        5,
        1, 1, 1, 2, 2,
        5,
        2, 1, 3, 1, 2,
        10,
        816783332, 961989300, 1897270484, 1587833932, 2093097502, 760094607, 1677327493, 825340682, 903966401, 1663982729
    };
    int t = 0;
    int testcase = input[t];
    t++;
    for (int tc = 0; tc < testcase; tc++) {
        int n = input[t];
        t++;
        int *a = new int[100009];
        for (int i = 0; i < n; i++) {
            a[i] = input[t];
            t++;
        }
        mrroot501::mergeSort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
