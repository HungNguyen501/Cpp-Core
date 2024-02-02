#include <iostream>
#include <fstream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

void solution(int arr[], int n, int k) {
    int lock;
    int i = 0;
    int count = 0;
    while (i < n) {
        lock = arr[i] + k;
        while (i < n && arr[i] <= lock) i++;
        i--;
        lock = arr[i] + k;
        count++;
        while (i < n && arr[i] <= lock) i++;
    }
    cout << count << "\n";

}

int main() {
    ifstream fi;
    fi.open("./input.txt");
    int n, k;
    int arr[100001];

    fi >> n >> k;
    for (int i = 0; i < n; i++) {
        fi >> arr[i];
    }
    fi.close();

    quickSort(arr, 0, n-1);
    solution(arr, n, k);
    return 0;
}

