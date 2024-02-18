#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Stack{
    private:
        T* stack[1000];
        int len;

    public:
        Stack() {
            len = -1;
        }

        void push(T value) {
            len++;
            stack[len] = &value;
        }

        void pop() {
            if (len == -1) {
                cout << "Stack is empty" << endl;
                return;
            }

            stack[len] = nullptr;
            len--;
        }

        bool isEmpty() {
            if (len == -1) return true;
            return false;
        }

        int size() {
            if (len == -1) {
                return 0;
            }
            return len + 1;
        }

        void printStack() {
            for (int i = 0; i <= len; i++) {
                cout << *stack[i] << " ";
            }
            cout << endl;
        }

};


int main() {
    Stack <string>s;

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
