#include <iostream>
using namespace std;

// O(2^(n^2))
int recurCountPaths(bool a[100][100], int row, int col, int n, int des[2]) {
    if (!a[row][col]) return 0;
    if (row == des[0] && col == des[1]) return 1;
    return recurCountPaths(a, row+1, col, n, des) + recurCountPaths(a, row, col+1, n, des);
}

// O(n^2)
int memoCountPaths(bool a[100][100], int row, int col, int n, int des[2], int path[100][100]) {
    if (!a[row][col]) return 0;
    if (row == des[0] && col == des[1]) return 1;
    if (path[row][col] == 0) {
        path[row][col] = memoCountPaths(a, row+1, col, n, des, path) + memoCountPaths(a, row, col+1, n, des, path);
    }

    return path[row][col];
}

int main() {
    bool a[100][100] = {false};
    int n = 8;
    int des[2] = {n-1, n-1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = true;
        }  
    }

    a[1][2] = false;
    a[1][6] = false;
    a[2][4] = false;
    a[3][0] = false;
    a[3][2] = false;
    a[3][5] = false;
    a[4][2] = false;
    a[5][3] = false;
    a[5][4] = false;
    a[5][6] = false;
    a[6][1] = false;
    a[6][5] = false;

    /*
    1 1 1 1 1 1 1 1
    1 1 0 1 1 1 0 1
    1 1 1 1 0 1 1 1
    0 1 0 1 1 0 1 1
    1 1 0 1 1 1 1 1
    1 1 1 0 0 1 0 1
    1 0 1 1 1 0 1 1
    1 1 1 1 1 1 1 1
    */
       
    cout << "Number of paths (recursion): " << recurCountPaths(a, 0, 0, n, des) << endl;

    int path[100][100] = {0};
    cout << "Number of paths (memoization): " << memoCountPaths(a, 0, 0, n, des, path) << endl;

    system("pause");
    return 0;
}