#ifndef _MRROOT501_QUEUE_H_
#define _MRROOT501_QUEUE_H_

#include <iostream>
// #include "message.h"

namespace mrroot501 {

template <typename T>
class Mrroot501Queue {
public:
    unsigned int max_length, length;
    int head, tail;
    T *arr;
    Mrroot501Queue();
    Mrroot501Queue(unsigned int max_length);
    unsigned int getSize();
    bool isEmpty();
    bool isFull();
    void enqueue(T value);
    T dequeue();
    std::string print();
};

} // namespace mrroot501

#endif
