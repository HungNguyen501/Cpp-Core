#include <iostream>
#include <fstream>
using namespace std;

void mergeHalfs(int *a, int leftStart, int rightEnd, long long &inver) {
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int left = leftStart, right = rightStart;
    int temp[100009];
    int index = leftStart;
    while (left <= leftEnd && right <= rightEnd)
    {
        if (a[left] <= a[right]) {
            temp[index] = a[left];
            left++;
        }
        else {
            temp[index] = a[right];
            right++;
            inver += (leftEnd - left + 1);
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

    for (int i = leftStart; i <= rightEnd; i++)
        a[i] = temp[i];
    int debug = 0;
}

void mergeSort(int *a, int leftStart, int rightEnd, long long &inver) {
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd) / 2;
    mergeSort(a, leftStart, middle, inver);
    mergeSort(a, middle + 1, rightEnd, inver);
    mergeHalfs(a, leftStart, rightEnd, inver);
}

int main() {
    ifstream read;
    read.open("D:\\Projects\\CPP\\Data Structure and Algorithms\\Merge Sort\\input.txt");

    int testcase;
    read >> testcase;
    for (int tc = 0; tc < testcase; tc++) {
        int n;
        int *a = new int[100009];
        long long inver = 0;
        read >> n;
        for (int i = 0; i < n; i++)
            read >> a[i];
        mergeSort(a, 0, n - 1, inver);
        cout << inver << endl;
    }
    
    system("pause");
    return 0;
}
