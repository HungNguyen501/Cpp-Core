#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "FileEngine.h"
#include "StringEngine.h"
using namespace std;

// Read random line of file
void randLine() {
    // Get info from
    FILE *fi = openFile("partition_info.txt", "r");
    char buffer[10000];

    // Read total_partiton, partition_size, num_lines_last_partition
    fgets(buffer, 10000, fi);
    vector<string> info  = split(string(buffer), ' ');
    // Remove break line character for last element
    info[2].pop_back();
    // Read total_lines
    fgets(buffer, 10000, fi);
    info.push_back(string(buffer));

    unsigned long long total_lines = strtoull(info[3].c_str(), nullptr, 10);
    unsigned long long partition_size = strtoull(info[1].c_str(), nullptr, 10);
    cout << "total_lines=" << total_lines << endl;
    cout << "partition_size=" << partition_size << endl;

    default_random_engine generator(time(NULL)); // Get random value when re-running
    // default_random_engine generator;
    uniform_int_distribution<long long unsigned> distribution(0,total_lines);

    for (int i = 0; i < 7; i++) {
        unsigned long long rand_number = distribution(generator);
        cout << "rand_number=" << rand_number << endl;

        unsigned long long partition = rand_number/partition_size;
        unsigned long long index = rand_number%partition_size;

        cout << "partition=" << partition << endl;
        cout << "index=" << index << endl;

        char *line = getLineContent(partition+1, index);

        cout << line << endl;
    }
    

}

int main() {
    char input_file[] = "input.txt";
    char folder_path[] = ".\\partition_file";
    
    // Partition input file and print random line
    partitionFile(input_file, 100000);

    /*
    After reading input file, read random in range of 1-total lines
    */
    // randLine();


    system("Pause");
    return 0;
}