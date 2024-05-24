#include <iostream>
#include "Libs.h"

using namespace std;

int main() {
    cout << sum(1, 2) << endl;

    Person p = Person("hung");
    p.printName();

    helloWorld();
    // var_from_header = 5;

    system("pause");
    return 0;
}