#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

long factorial[14] = {0};

void fillFactorialArr(long factorial[]) {
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i < 14; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

int main() {
    ifstream read;
    read.open("./input.txt");
    fillFactorialArr(factorial);
    int arr[100001] = {0};
    int cur_sum = 0;
    for (int i = 10; i <= 100001; i++) {
        int temp = i;
        int sum = 0;
        while (temp > 0) {
            sum += factorial[temp % 10];
            temp /= 10;
        }
        if (sum % i == 0) {
            cur_sum += i;
        }
        arr[i] = cur_sum;
        if (sum % i == 0) {
            cout << arr[i] << "\n";
        }
    }
    

    return 0;
}
