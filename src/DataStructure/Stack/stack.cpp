#include <iostream>

namespace mrroot501 {

template <typename T>
class Stack{
private:
    T* stack;
    int space;
    int pointer;
public:
    Stack() {
        this->pointer = -1;
        this->space = 1000;
        this->stack = new T[1000];
    }
    Stack(int space) {
        this->pointer = -1;
        this->space = space;
        this->stack = new T[space];
    }
    void push(T value) {
        if (this->pointer >= this->space) {
            std::cout << "Cannot add an element from stack beacause it's space is full\n";
            return;
        }
        this->pointer++;
        this->stack[pointer] = value;
    }
    void pop();
    bool isEmpty() {
        return (pointer == -1);
    }
    int size() {
        return this->pointer + 1;
    }
    void printStack() {
        for (int i = 0; i <= this->pointer; i++) {
            std::cout << this->stack[i] << " ";
        }
        std::cout << "\n";
    }

};

template<> void Stack<int>::pop() {
    if (this->isEmpty()) {
        std::cout << "Cannot pop an element from stack beacause it is empty\n";
        return;
    }
    this->stack[pointer] = 0;
    this->pointer--;
};

template <>
void Stack<std::string>::pop() {
    if (this->isEmpty()) {
        std::cout << "Cannot pop an element from stack beacause it is empty\n";
        return;
    }
    this->stack[pointer] = "";
    this->pointer--;
}

template class Stack<std::string>;
template class Stack<int>;

} // namespace mrroot501