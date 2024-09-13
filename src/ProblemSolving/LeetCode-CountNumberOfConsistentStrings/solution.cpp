#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

/*
    Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12
*/

int countConsistentStrings(string allowed, vector<string>& words) {
    bitset<26> LookUp = 0;
    int count = 0;
    for(char c: allowed) {
        LookUp[c - 'a'] = 1;
    }
    for(string word: words) {
        int consistent = 1;
        for(char c: word) {
            if(LookUp[c - 'a'] == 0) {
                consistent = 0;
                break;
            }
        }
        count+=consistent;
    }
    return count;
}
