#include <iostream>
#include "header.h"
using namespace std;

int main() {
    int arr[] = {1, 4, 2, 5, 0};
    cout << findElement(arr, sizeof(arr)/ sizeof(int)) << "\n";
    return 0;
}

