#ifndef _STRING_ENGINE_
#define _STRING_ENGINE_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string str, char seperator)
{
    vector<string> result;

    int i = 0;
    int startIndex = 0, endIndex = 0;

    while (i <= str.size()) {
        if (str[i] == seperator || i == str.size()) {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            result.push_back(subStr);
            startIndex = endIndex + 1;
        }

        i++;
    }

    return result;
}

bool contain(string s, char c) {
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == c) return true;
    }

    return false;
}

// Return a*b
vector<int> multiple(vector<int> a, int b) {
    for (int i = 0; i < a.size(); i++)
            a[i]*=b;
        
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < 10)
            continue;     
        if (i == a.size() - 1)
            a.push_back(0);           
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }

    return a;
}

// Return a+b
vector<int> sum(vector<int> a, vector<int> b) {
    if (a.size() < b.size()) {
        cout << "Return NULL beacause number of digits of a < number of digits of b" << endl;
        return vector<int> ();
    }

    for (int i = 0; i < b.size(); i++) {
        a[i] += b[i];
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] < 10) continue;
        if (i == a.size() - 1) a.push_back(0);

        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }

    return a;
}

#endif