#ifndef _FILE_ENGINE_
#define _FILE_ENGINE_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <random>
#include "StringEngine.h"
using namespace std;

// INT32_MAX=2,147,483,647
#define MAX_BUFFER_SIZE INT32_MAX
#define MAX_NUM_LINE INT32_MAX
int const MAX_NUM_PARTITION = 1000;

FILE *openFile(char *file_name, char *mode) 
{
    FILE *fp = fopen(file_name, mode);

    if (fp == NULL) {
        perror("Error while opening file.\n");
        exit(EXIT_FAILURE);
    }

    return fp;
}

// Return total lines of file
string totalLines(int _partition_size, 
                    int _total_partiton, 
                    int _num_lines_last_partition)
{
    vector<int> partition_size = numberToVector(_partition_size);
    vector<int> total_partiton = numberToVector(_total_partiton - 1);
    vector<int> num_lines_last_partition = numberToVector(_num_lines_last_partition);

    vector<int> score = sum(multiple(partition_size, total_partiton), num_lines_last_partition);

    string total_lines = "";
    for (int i = score.size() - 1; i >= 0; i--) {
        total_lines+=to_string(score[i]);
    }

    return total_lines;
}

// Partition a file to multiple files
void partitionFile(char *input_file, 
            int partition_size) // number of lines for each partition_file
{
    FILE *fi = openFile(input_file, "r");
    FILE *fo;

    char *buffer = new char[MAX_BUFFER_SIZE];
    char index_file[50];
    int count_line = 0;
    int count_partition = 1;
    unsigned long long current_line = 1;

    default_random_engine generator(time(NULL)); // Get random value when re-running
    // default_random_engine generator;
    string rand_line;

    while(fgets(buffer, MAX_BUFFER_SIZE, fi)) {
        // Calculate uniform distribution while adding a new line
        uniform_real_distribution<long double> distribution(0 ,current_line);

        if (distribution(generator) <= 1) {
            rand_line = convertToString(buffer, strlen(buffer));
        }
        current_line++;

        // Handle when line is not loaded fully to buffer
        if (buffer[strlen(buffer) -1 ] != '\n' && !feof(fi)) {            
        	// Warning buffer overflow for reading that line
            cout << "Line " << count_line << " of partition " << count_partition << " is not loaded fully" << endl;

            // Keep reading still for end of that line
            while(fgets(buffer, sizeof(buffer), fi)) {
                if (buffer[strlen(buffer) -1] == '\n') {
                    break;
                }
            }
        }

        if (count_line == 0) {
            // Assign indexfile="(count_line).txt"
            snprintf(index_file, sizeof(index_file), ".\\partition_file\\%d.txt", count_partition);
            fo = openFile(index_file, "w");
        }

        fwrite(buffer, sizeof(char), strlen(buffer), fo);
        count_line++;

        if (count_line == partition_size) {
            // Close partition_file
            fclose(fo);

            count_line = 0;
            count_partition++;
        }              
        
    }
    fclose(fi);

    // Print rand_line after reading file completely
    cout << "Random line: " << endl;
    cout << rand_line << endl;

    // Save info of last partition_file to file
    FILE *fp = openFile("partition_info.txt", "wb");
    char info[100000];
    
    // Save count_partition count_line 
    auto format = "%d %d";
    snprintf(info, sizeof(info), "%d %d %d\n", count_partition, partition_size, count_line);
    fwrite(info, sizeof(char), strlen(info), fp);
                    
    string total_lines = totalLines(partition_size, count_partition, count_line);
    strcpy(info, total_lines.c_str());
    fwrite(info, sizeof(char), total_lines.length(), fp);
    
    fclose(fp);
}    

char *getLineContent(int partition, 
                    int index)
{
    char partition_file[10000];
    snprintf(partition_file, sizeof(partition_file), ".\\partition_file\\%d.txt", partition);
    
    FILE* fi = openFile(partition_file, "r");
    char *buffer = new char[MAX_BUFFER_SIZE];

    for (int i = 0; i < index; i++) {
        fgets(buffer, MAX_BUFFER_SIZE, fi);
    }

    return buffer;
}                    

#endif