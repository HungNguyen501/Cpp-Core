#include <iostream>
#include <fstream>
using namespace std;

void func1() {
    char a[2020*1024];
}

int main() {
    ifstream read;
    read.open("D:\\Projects\\CPP\\Data Structure and Algorithms\\Test\\input.txt");

    int a;
    unsigned int x = -1;
    
    cout << sizeof(unsigned int) << endl;

    // Check memory of stack
    func1();

    read >> a;
    cout << a << endl;

    system("pause");
    return 0;
}