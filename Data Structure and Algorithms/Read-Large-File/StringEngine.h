#ifndef _STRING_ENGINE_
#define _STRING_ENGINE_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define abs(a) ((a > 0) ? a : -a)

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

template <typename T>
vector<int> numberToVector(T a) {
    vector<int> result;

    while(a > 10) {
        // cout << a%10 << endl;
        result.push_back(a%10);
        a/=10;
    }

    result.push_back(a);

    return result;
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

// Compare wheather a is greater than b or not
bool isGreater(vector<int> a, vector<int> b) {
    if (a.size() < b.size()) return false;
    if (a.size() > b.size()) return true;

    // Size of a equals size of b
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == b[i]) 
            continue;

        if (a[i] > b[i]) 
            return true;
        else
            return false;
    }

    return false;
}

// Return a*(int)b
vector<int> multipleWithInt(vector<int> a, int b) {
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

// Return a*b
vector<int> multiple(vector<int> a, vector<int> b)
{
    int len1 = a.size();
    int len2 = b.size();
    if (len1 == 0 || len2 == 0)
        return vector<int> (1, 0);
 
    // will keep the result number in vector in reverse order
    vector<int> result(len1 + len2, 0);
 
    // Below two indexes are used to find positions
    int index_of_a = 0;
    int index_of_b = 0;
     
    for (int i= 0; i < len1; i++)
    {
        int carry = 0;
        int n1 = a[i];
 
        index_of_b = 0;
                 
        for (int j = 0; j < len2; j++)
        {
            // Take current digit of b
            int n2 = b[j];
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[index_of_a + index_of_b] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[index_of_a + index_of_b] = sum%10;
 
            index_of_b++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[index_of_a + index_of_b] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in a.
        index_of_a++;
    }
 
    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] != 0) break;
        result.pop_back();
    }
 
    return result;
}

// Return a/b
vector<int> divide(vector<int> a, int b) {
    vector<int> score;
    int index = a.size() -1;
    int dividend = a[index--];

    while(dividend < b) {
        dividend = dividend*10 + a[index--];
    }

    while(index >= -1) {
        score.insert(score.begin(), (dividend/b));
        dividend = (dividend%b)*10 + a[index--];
    }

    if (score.size() == 0) {
        score.push_back(0);
    }

    return score;
}

// Return a+b
vector<int> sum(vector<int> a, vector<int> b) {
    if (a.size() < b.size()) {
        cout << "Return NULL beacause number of digits of a is less than number of digits of b" << endl;
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

// Return a-b
vector<int> subtract(vector<int> a, vector<int> b) {
    if (isGreater(a, b) == false) {
        cout << "a must be greater than b" << endl;
        return vector<int> ();
    }

    for (int i = 0; i < b.size(); i++) {
        int temp = a[i] + 10 - b[i];
        a[i] = (a[i] > b[i]) ? temp%10 : -temp%10;
    }
    
    bool minus_one = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 0) {
            a[i] = abs(a[i]);
            if (minus_one) {
                a[i] = (a[i] + 10 - 1)%10;
                if (a[i] == 9) { // a[i] = 0 + 10 - 1
                    minus_one = true;
                    continue;
                }
            }
            minus_one = false;
        } else {
            a[i] = abs(a[i]);
            if (minus_one) a[i]--;
            minus_one = true;    
        }
        
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != 0) break;
        a.pop_back();
    }
    
    return a;
}

#endif