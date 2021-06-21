#include <iostream>
#include <fstream>
#include <map>
using namespace std;

void convertToBinary(unsigned int n)
{
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    ifstream read;
    read.open("D:\\Projects\\CPP\\Test\\input.txt");

    cout << "Hello wrold" << endl;


    system("pause");
    return 0;
}