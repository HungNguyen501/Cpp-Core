#include <iostream>
#include <fstream>
#include "MergeSort.h"
using namespace mrroot501;
using namespace std;

int main() {
    ifstream read;
    read.open("MergeSort/input.txt");

    int testcase;
    read >> testcase;
    for (int tc = 0; tc < testcase; tc++) {
        int n;
        int *a = new int[100009];
        read >> n;
        for (int i = 0; i < n; i++)
            read >> a[i];
        mergeSort(a, 0, n - 1);
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
