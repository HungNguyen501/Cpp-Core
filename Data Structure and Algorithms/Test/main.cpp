#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream read;

    read.open("D:\\Projects\\CPP\\Data Structure and Algorithms\\Test\\input.txt");

    int a;
    read >> a;

    cout << a << endl;

    system("pause");
    return 0;
}