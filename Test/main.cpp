#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream read;
    read.open("D:\\Projects\\CPP\\Test\\input.txt");

    long n, dif, count = 0;
    map <long, long> arr;

    read >> n;

    for (int i = 0; i < n; i++) {
        long temp;
        read >> temp;
        arr[temp]++;
    }

    read >> dif;

    for (auto i = arr.begin(); i != arr.end(); i++) {
        long key = i->first;
        long value = i->second;

        if (value == 0) {
            continue;
        }
        
        long k = 0;
        while (i->second > 0) {
            try
            {
                if (arr[key + dif + k] > 0) {
                    arr[key + dif + k]--;
                    i->second--;
                    count++;
                }
                
            }
            catch(const exception& e)
            {
                int do_nothing  = 1;
                k++;
            }
            
        }
    }

    cout << count << endl;

    system("pause");
    return 0;
}