#include <iostream>
#include <fstream>
using namespace std;

void mergeHalfs(int *a, int leftStart, int rightEnd) {
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int left = leftStart, right = rightStart;

    int temp[rightEnd - leftStart + 1];
    int index = 0;
    while (left <= leftEnd && right <= rightEnd)
    {
        if (a[left] <= a[right]) {
            temp[index] = a[left];
            left++;
        }
        else {
            temp[index] = a[right];
            right++;
        }
        index++;
    }

    while (left <= leftEnd)
    {
        temp[index] = a[left];
        left++;
        index++;
    }

    while (right <= rightEnd)
    {
        temp[index] = a[right];
        right++;
        index++;
    }

    for (int i = leftStart; i <= rightEnd; i++) {
        a[i] = temp[i - leftStart];
    }
}

void mergeSort(int *a, int leftStart, int rightEnd) {
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd) / 2;
    mergeSort(a, leftStart, middle);
    mergeSort(a, middle + 1, rightEnd);
    mergeHalfs(a, leftStart, rightEnd);
}

int main() {
    ifstream read;
    read.open("D:\\Projects\\CPP\\Data Structure and Algorithms\\Merge Sort\\input.txt");

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
    
    system("pause");
    return 0;
}
