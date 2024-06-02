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
        this->pointer = 0;
        this->space = 1000;
        this->stack = new T[1000];
    }
    Stack(int space) {
        this->pointer = 0;
        this->space = space;
        this->stack = new T[space];
    }
    void push(T value) {
        if (this->pointer >= this->space) {
            std::cout << "Cannot add an element from stack beacause it's space is full\n";
            return;
        }
        this->stack[pointer] = value;
        this->pointer++;
    }
    void pop();
    bool isEmpty() {
        return (this->size() == 0);
    }
    int size() {
        return this->pointer;
    }
    void printStack() {
        for (int i = 0; i < this->pointer; i++) {
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
    this->pointer--;
    this->stack[pointer] = 0;
};

template <>
void Stack<std::string>::pop() {
    if (this->isEmpty()) {
        std::cout << "Cannot pop an element from stack beacause it is empty\n";
        return;
    }
    this->pointer--;
    this->stack[pointer] = "";
}

template class Stack<std::string>;
template class Stack<int>;

} // namespace mrroot501