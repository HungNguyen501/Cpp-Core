#include <iostream>
using namespace std;

int n = 3;
void printMatrix(int a[3][3]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
        
}


int main() {   
    int a[3][3] = {
                {1,2,3}, 
                {4,5,6}, 
                {7,8,9}
    };
    
    // Step 1: transpose matrix
    /*
    1 4 7
    2 5 8
    3 6 9
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    
    
    // Step 2: flip horizontally
    /*
    7 4 1
    8 5 2
    9 6 3
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            int temp = a[i][n-1-j];
            a[i][n-1-j] = a[i][j];
            a[i][j] = temp;
        }
    }
    printMatrix(a);
    return 0;
}