#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    mrroot501::Mrroot501Queue<string> str_q(4);
    str_q.enqueue("abc");
    str_q.enqueue("2");
    str_q.enqueue("3");
    str_q.enqueue("4");
    str_q.enqueue("5");
    cout << str_q.print() << "\n";
    cout << "size=" << str_q.getSize() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "size=" << str_q.getSize() << "\n";
    cout << str_q.print() << "\n";
    str_q.enqueue("abc");
    str_q.enqueue("2");
    str_q.enqueue("3");
    str_q.enqueue("4");
    str_q.enqueue("5");
    cout << str_q.print() << "\n";
    cout << "size=" << str_q.getSize() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << "dequeue: " << str_q.dequeue() << "\n";
    cout << str_q.print() << "\n";
    str_q.enqueue("abc");
    str_q.enqueue("2");
    str_q.enqueue("3");
    str_q.enqueue("4");
    str_q.enqueue("4");
    str_q.enqueue("4");
    str_q.enqueue("4");
    str_q.enqueue("4");
    str_q.enqueue("4");
    str_q.enqueue("4");
    str_q.enqueue("5");
    cout << str_q.print() << "\n";
    return 0;
}



