#include <iostream>
#include "Mrroot501HashTable.h"
using namespace std;

int main() {
    Mrroot501HashTable<string> myHT;
    myHT.add("abc");
    myHT.add("cdf");
    myHT.add("aa");
    myHT.add("ff");
    myHT.add("cc");
    myHT.add("ss");
    myHT.add("ss");
    myHT.printHashTable();
    myHT.remove("cdf");
    myHT.remove("cdd");
    myHT.printHashTable();
    myHT.add("abc");
    myHT.add("acv");
    myHT.add("vcs");
    myHT.removeRandom();
    myHT.printHashTable();
    return 0;
}
