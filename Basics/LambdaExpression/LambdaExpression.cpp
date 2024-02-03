#include <iostream>
using namespace std;

int main() {
    auto egNumber = [&](int number) {
        while (number > 2) {
            number /= 2;
        }
        return number;
    };

    cout << "Example with a number: " << egNumber(10) << "\n";

    auto glambda = [](int a, int b) { return a < b; };
    cout << "Example with a comparision: " << glambda(3, 4) << "\n";

    return 0;
}
