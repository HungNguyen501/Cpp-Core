#include <iostream>
#include <string>
#include <vector>
#include "FileEngine.h"
#include "StringEngine.h"
using namespace std;

long long getTotalLines(char *folder_path) {
    long long total_lines = 0;
    // vector<string> list_files = listFiles(folder_path);

    // for (int i = 0; i < list_files.size(); i++) {
    //     if
    //     string index = strtok(list_files[i], "_");
    //     string num_rows = "";


    // }
    return 1;
}

template <typename T>
void printVector(vector<T> v, bool reverse, string seperator) {
    if (reverse) {
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i] << seperator;
    } else {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << seperator;
    }
    
    cout << endl;  
}

// // Read random line of file
// char *randLine(string rand_line) {

// }

int main() {
    char input_file[] = "input.txt";
    char folder_path[] = ".\\partition_file";
    // partitionFile(input_file, 100000);

    // string *list_files = listFiles(folder_path);

    
    // getTotalLines(folder_path);

    //  vector<string> result = split("10_1000.txt", '_');

    //  cout << list_files[0] << endl;
    //  cout << list_files[4] << endl;
    //  cout << result[1] << endl;

    vector<int> list_files = listFiles(folder_path);

    printVector(list_files, false, " ");

    // vector<int> a;
    // a.push_back(9);
    // vector<int> m1 = multiple(a, 2);
    // m1 = sum(m1, m1);


    

    system("Pause");
    return 0;
}