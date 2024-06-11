#ifndef _MRROOT501_MESSAGE_QUEUE_H_
#define _MRROOT501_MESSAGE_QUEUE_H_

#include "../Queue/queue.h"

namespace mrroot501 {

template <class T>
class MessageQueue : public Mrroot501Queue<Message<int>> {
public:
    long byte_size, byte_capacity;
    MessageQueue();
    MessageQueue(int max_length, int byte_capacity);
    long getByteSize();
    bool isFull();
    // bool isEmpty();
    void enqueue(T value, bool forced = false);
    T front();
    T dequeue();
};

} // namespace mrroot501

#endif
