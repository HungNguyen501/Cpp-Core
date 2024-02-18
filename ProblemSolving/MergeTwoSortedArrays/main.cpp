#include <iostream>
using namespace std;

int* mergeTwoSortedArrays(int a[], int b[], int len1, int len2) {
    static int arr[1000];
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        int temp;
        if (a[i] < b[j]) {
            temp = a[i];
            i++;
        } else {
            temp = b[j];
            j++;
        }
        arr[k] = temp;
        k++;
    }
    for (int t1 = i; t1 < len1; t1++) {
        arr[k] = a[t1];
        k++;
    }
    for (int t2 = j; t2 < len2; t2++) {
        arr[k] = b[t2];
        k++;
    }
    return arr;
}

int main() {
    int a[] = {1, 4, 9, 15, 21};
    int b[] = {2, 3, 5, 8, 17, 20, 29, 30};
    int len1 = sizeof(a) / sizeof(int);
    int len2 = sizeof(b) / sizeof(int);
    int* arr = mergeTwoSortedArrays(a, b, len1, len2);

    for (int i = 0; i < len1 + len2; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
