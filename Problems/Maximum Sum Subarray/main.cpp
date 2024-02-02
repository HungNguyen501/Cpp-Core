#include <iostream>
using namespace std;

#define MAX(a,b) (a>b ? a:b)

int main() {
    int a[] = {-2,2,5,-11,6};

    int temp_sum = 0;
    int max_sum = 0;
    int n = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i< n; i++) {
        temp_sum = MAX(temp_sum+a[i], a[i]);
        max_sum = MAX(temp_sum, max_sum);
    }

    cout << max_sum << endl;

    system("pause");
    return 0;
}