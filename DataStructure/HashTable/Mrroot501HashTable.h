#ifndef _BINARYTREE_
#define _BINARYTREE_

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Mrroot501HashTable {
private:
    hash<T> hasher;
    vector<T> arr;
    int* hashTable;
    int space;
public:
    Mrroot501HashTable() {
        // Default Constructor
        this->space = 1000000;
        this->hashTable = new int[space];
        for (int i = 0; i < space; i++) {
            this->hashTable[i] = -1;
        }
    }

    Mrroot501HashTable(int space) {
        this->hashTable = new int[space];
        for (int i = 0; i < space; i++) {
            this->hashTable[i] = -1;
        }
    }

    void add(T value) {
        int i = hasher(value) % space;
        if (hashTable[i] != -1) {
            std::cout << "Value existed: " << value << "\n";
            return;
        }
        int index = arr.size();
        hashTable[i] = index;
        arr.push_back(value);
        std::cout << "Value added: " << value << "\n";
    }

    void remove(T value) {
        int i = hasher(value) % space;
        if (hashTable[i] == -1) {
            std::cout << "Value not found: " << value << "\n";
            return;
        }
        int index = hashTable[i];
        hashTable[i] = -1;
        arr[index] = arr[arr.size() - 1];
        arr.pop_back();
        std::cout << "Removed " << value << "\n";
    }
    void removeRandom() {
        int randIndex = rand() % arr.size();
        std::cout << "Removed " << arr[randIndex] << "\n";
        hashTable[hasher(arr[randIndex]) % space] = -1;
        arr[randIndex] = arr[arr.size() - 1];
        arr.pop_back();
    }

    void printHashTable() {
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

#endif
