#ifndef _STACK_H_
#define _STACK_H_

namespace mrroot501 {

template <typename T> class Stack{
public:
        Stack();
        void push(T value);
        void pop();
        bool isEmpty();
        int size();
        void printStack();
};

} // namespace mrroot501

#endif