#include <iostream>
#include "Libs.h"
using namespace std;

Person::Person(string name) {
    this->name = name;
}

void Person::printName() {
    cout << this->name << endl;
}

void helloWorld() {
    cout << "Hello world!" << endl;
}


int sum(int a, int b) {
    return a + b;
}
