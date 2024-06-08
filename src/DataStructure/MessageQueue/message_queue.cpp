#include <iostream>
#include "../Queue/queue.h"

namespace mrroot501 {

struct Metadata
{
    long timestamp;
    unsigned int index;
};


class Message {
public:
    Metadata metadata;
    std::string payload;
};

class MessageQueue : public Mrroot501Queue<Message> {
public:
    MessageQueue() {};
    MessageQueue(int capacity) {
        this->capacity = capacity;
        this->head = this->tail = this->size = 0;
        this->arr = new Message[1000000];
    }
    void getSize() {

    }
    void isFull() {

    }
    void isEmpty() {

    }
};

} // namespace mrroot501
