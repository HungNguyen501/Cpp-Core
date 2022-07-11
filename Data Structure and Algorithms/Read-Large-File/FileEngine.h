#ifndef _FILE_ENGINE_
#define _FILE_ENGINE_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <dirent.h>
#include "StringEngine.h"
using namespace std;

#define MAX_BUFFER_SIZE INT32_MAX
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

// Partition a file to multiple files
void partitionFile(char *input_file, 
            int partition_size) // number of lines for each partition_file
{
    FILE *fi = openFile(input_file, "r");
    FILE *fo;

    char *buffer = new char[MAX_BUFFER_SIZE];
    char index_file[50];
    long long count_line = 1;
    int count_partition = 1;

    while(!feof(fi)) {
        fgets(buffer, MAX_BUFFER_SIZE, fi);

        if (buffer[strlen(buffer) -1 ] != '\n') {
            cout << "Line " << count_line << " of partition " << count_partition << " is not loaded fully" << endl;
        }

        if (count_line == 1) {
            // Assign indexfile="(count_line).txt"
            snprintf(index_file, sizeof(index_file), ".\\partition_file\\%d.txt", count_partition);
            fo = openFile(index_file, "w");
        }

        fwrite(buffer, sizeof(char), strlen(buffer), fo);
        count_line++;

        if (count_line == partition_size || feof(fi)) {
            // Close partition_file
            fclose(fo);

            if (feof(fi)) {
                // Rename partition_file by adding total lines to file_name
                char new_name[50];
                snprintf(new_name, sizeof(new_name), ".\\partition_file\\%d_%d.txt", count_partition, count_line);
                
                if (rename(index_file, new_name) != 0) {
                    perror("Error while rename file.\n");
                    exit(EXIT_FAILURE);
                }
            }

            count_line = 1;
            count_partition++;
        }
        
    }

    fclose(fi);
}

// string *listFiles(char *path) {
//     string *list_files = new string[MAX_NUM_PARTITION];
//     // Pointer for directory entry
//     struct dirent *de;
  
//     DIR *dr = opendir(path);
  
//     // opendir returns NULL if couldn't open directory
//     if (dr == NULL) {
//         cout << "Could not open current directory" << endl;
//         return list_files;
//     }

//     int i = 0;
//     while( (de = readdir(dr)) != NULL) {
//         string file_name = de->d_name;
//         if (file_name != "." && file_name != "..") {
//             list_files[i] = file_name.substr(0, file_name.length() - 4);
//             i++;
//         }
//     }  
//     closedir(dr); 

//     return list_files;
// }

vector<int> listFiles(char *path) {    
    DIR *dr = opendir(path);
  
    // opendir returns NULL if couldn't open directory
    if (dr == NULL) {
        cout << "Could not open current directory" << endl;
        return vector<int> ();
    }

    // Pointer for directory entry
    // struct dirent *de1;
    // int num_files = 0;
    // while( (de1 = readdir(dr)) != NULL) {
    //     num_files++;
    // }

    // num_files-=2;

    vector<int> list_files(13, 0);
    // Pointer for directory entry
    struct dirent *de2;
    while( (de2 = readdir(dr)) != NULL) {
        string file_name = de2->d_name;
        if (file_name != "." && file_name != "..") {
            file_name = file_name.substr(0, file_name.length() - 4);


            if (contain(file_name, '_')) {
                vector<string> split_str = split(file_name, '_');
                list_files[stoi(split_str[0]) - 1] = stoi(split_str[1]);
                break;
            }
        }
    }

    closedir(dr); 

    return list_files;
}

#endif