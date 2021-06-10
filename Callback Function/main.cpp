#include <iostream>
using namespace std;

void func1() {
    cout << "Hello wrold!" << endl;
}

void func2(void (*ptr) ()) {
    (*ptr)();
}

void sum(int a, int b) {
    cout << "Sum of " << a << " and " << b << " equals: " << a + b << endl;
}

void printSum(void (*ptr)(int a, int b), int a, int b){
    (*ptr)(a, b);
}

int main() {
    // Example 1
    void (*ptr1)() = &func1;
    func2(ptr1);

    // Example 2
    void (*ptr2)(int a, int b) = &sum;
    printSum(ptr2, 1, 2);

    system("pause");
    return 0;
}