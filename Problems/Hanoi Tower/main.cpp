#include <iostream>
using namespace std;

void solving(int n, char a, char b, char c) {
    if (n==1) {
        printf("Move %c to %c\n", a, b);
        return;
    }
    
    solving(n-1, a, c, b);
    solving(1, a, b, c);
    solving(n-1, c, b, a);
}

int main() {
    // Move 3 disks from A to B
    solving(3, 'A', 'B', 'C');

    system("pause");
    return 0;
}