#include <iostream>
using namespace std;

#define NUM_CHAR 256
#define MAX(a,b) ( (a > b) ? a : b)

void badCharHeuristic(string pattern, int badChar[]) {
    for (int i = 0; i < NUM_CHAR; i++) {
        badChar[i] = -1;
    }

    // Find last occurrence of character in pattern string
    for (int i= 0; i < pattern.size(); i++) {
        badChar[(int) pattern[i]] = i;
    }
}

void search(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int badChar[NUM_CHAR];
    int s = 0; // s is shift value of the pattern with respect to text

    badCharHeuristic(pattern, badChar);

    while(s + m <= n) {
        int j = m-1;

        // find last missmatched index
        while (j >= 0 && pattern[j] == text[s+j]) j--;

        if (j < 0) {
            // bing go
            cout << "bing go at " << s << endl;

            /* Shift pattern to the last occurrence*/
            /*The condition s+m < n is necessary for the case when pattern occurs at the end of text  
            text[s+m] occurrs Exception with s+m >= n: out of elements range of text*/
            s += ( (s+m < n) ? m - badChar[(int) text[s+m]] : 1);
        } else {
            s += MAX(1, j - badChar[(int) text[s+j]]);
        }
    }
}


int main() {
    string t = "gcaatgcctatgtgacc";
    string p = "tatgtg";

    search(t, p);

    system("pause");
    return 0;
}