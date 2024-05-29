#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Contact {
    string name, phonenumber;
};

void swap(Contact &a, Contact &b) {
    Contact tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void quickSort(vector <Contact> &contact, int left, int right) {
    if (left >= right) return;
    string pivot = contact[(left + right) / 2].name;
    int i = left, j = right;
    while (i <= j) {
        while (contact[i].name < pivot) i++;
        while (contact[j].name > pivot) j--;
        if (i <= j) swap(contact[i++], contact[j--]);
    }
    quickSort(contact, left, j);
    quickSort(contact, i, right);
}

int binarySearch(vector <Contact> contact, string name, int l, int h)
{
    if (l == h)
    {
        if (contact[l].name == name) return l;
        else return -1;
    }

    int m = (l + h) / 2;
    if (contact[m].name == name) return m;
    if (contact[m].name >= name) return binarySearch(contact, name, l, m - 1);
    else return binarySearch(contact, name, m + 1, h);
}

int main() {
    ifstream input;
    input.open("BinarySearch/input.txt");

    int n;
    string name;
    string num;

    input >> n;
    map <string, string> pBook;
    for (int i = 0; i < n; i++) {
        input >> name;
        input >> num;
        pBook[name] = num;
    }
    
    while(input >> name) {
        if (pBook.find(name) != pBook.end()) {
            cout << name << "=" << pBook.find(name)->second << endl;
        } else {
            cout << "Not found" << endl;
        }
    }

    return 0;
}
