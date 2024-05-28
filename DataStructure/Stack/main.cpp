#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    mrroot501::Stack <string> s;
    cout << s.size() << endl;
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.push("a");
    s.printStack();
    s.pop();
    s.pop();
    s.pop();
    s.printStack();
    return 0;
}
