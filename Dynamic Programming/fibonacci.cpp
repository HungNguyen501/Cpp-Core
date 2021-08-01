#include <iostream>
#include <time.h>
using namespace std;

int fibo_recur(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) {
        return 1;
    }

    return fibo_recur(n-1) + fibo_recur(n-2);
}

int fibo_momoization(int n, int memo[]) {
    if (n == 0) return 0;

    if (n == 1 || n == 2) {
        memo[n] = 1;
    }

    if (memo[n] == 0) {
        memo[n] = fibo_momoization(n-1, memo) + fibo_momoization(n-2, memo);
    } 
    
    return memo[n];
}

int fibo_bottom_up(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int fibo_arr[100] = {0};
    fibo_arr[1] = 1;
    fibo_arr[2] = 1;

    for (int i = 3; i <= n; i++) {
        fibo_arr[i] = fibo_arr[i-1] + fibo_arr[i-2];
    }

    return fibo_arr[n];
}


int main() {
    int n = 35;

    // recursion O(2^n)
    clock_t startTime1 = clock();
    cout << fibo_recur(n) << endl;
    cout << "Excution time: " << (clock() - startTime1) << "ms" << endl;

    // memoization O(n)
    clock_t startTime2 = clock();
    int memo[100] = {0};
    cout << fibo_momoization(n, memo) <<endl;
    cout << "Excution time: " << (clock() - startTime2) << "ms" << endl;

    // bottom up O(n)
    clock_t startTime3 = clock();
    cout << fibo_bottom_up(n) << endl;
    cout << "Excution time: " << (clock() - startTime3) << "ms" << endl;

    system("pause");
    return 0;
}