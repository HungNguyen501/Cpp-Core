#ifndef _LIBS_H_
#define _LIBS_H_

#include <iostream>
using namespace std;

void helloWorld();
int sum(int a, int b);

class Person{
public:
    string name;
    Person (string name);
    void printName();
};

#endif