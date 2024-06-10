#include <iostream>
#include <gtest/gtest.h>
#include "queue.h"
using namespace std;

TEST(TestQueue, tcInt) {
    mrroot501::Mrroot501Queue<int> int_q(1);
    EXPECT_EQ(int_q.dequeue(), -1);
    EXPECT_EQ(int_q.isEmpty(), true);
    int_q.enqueue(1);
    int_q.enqueue(2);
    int_q.enqueue(3);
    EXPECT_EQ(int_q.print(), "1 ");
    EXPECT_EQ(int_q.isEmpty(), false);
    EXPECT_EQ(int_q.dequeue(), 1);
    EXPECT_EQ(int_q.isEmpty(), true);
}

TEST(TestQueue, tcString) {
    mrroot501::Mrroot501Queue<std::string> str_q(5);
    str_q.enqueue("1");
    str_q.enqueue("2");
    str_q.enqueue("3");
    str_q.enqueue("4");
    str_q.enqueue("5");
    str_q.enqueue("6");
    str_q.enqueue("7");
    str_q.enqueue("8");
    EXPECT_EQ(str_q.print(), "1 2 3 4 5 ");
    EXPECT_EQ(str_q.isEmpty(), false);
    EXPECT_EQ(str_q.dequeue(), "1");
    EXPECT_EQ(str_q.dequeue(), "2");
    EXPECT_EQ(str_q.dequeue(), "3");
    str_q.enqueue("9");
    EXPECT_EQ(str_q.print(), "4 5 9 ");
    EXPECT_EQ(str_q.dequeue(), "4");
    str_q.enqueue("10");
    str_q.enqueue("11");
    str_q.enqueue("12");
    EXPECT_EQ(str_q.print(), "5 9 10 11 12 ");
    EXPECT_EQ(str_q.dequeue(), "5");
    EXPECT_EQ(str_q.dequeue(), "9");
    EXPECT_EQ(str_q.dequeue(), "10");
    EXPECT_EQ(str_q.dequeue(), "11");
    EXPECT_EQ(str_q.dequeue(), "12");
    EXPECT_EQ(str_q.dequeue(), "");
    EXPECT_EQ(str_q.dequeue(), "");
    EXPECT_EQ(str_q.isEmpty(), true);
}

TEST(TestQueue, testMessageType) {
    mrroot501::Mrroot501Queue<mrroot501::Message<int>> m_q(4);
    EXPECT_EQ(m_q.dequeue().isNull(), true);
    EXPECT_EQ(m_q.isEmpty(), true);
    m_q.enqueue(mrroot501::Message<int>());
    m_q.enqueue(mrroot501::Message<int>(mrroot501::Header<int>(), "dummy"));
    m_q.enqueue(mrroot501::Message<int>(mrroot501::Header<int>(-1), "foo"));
    m_q.enqueue(mrroot501::Message<int>(mrroot501::Header<int>(-1, 3513515351), "zombie"));
    m_q.enqueue(mrroot501::Message<int>(mrroot501::Header<int>(-1), "full"));
    m_q.enqueue(mrroot501::Message<int>(mrroot501::Header<int>(-1), "full"));
    EXPECT_EQ(m_q.isFull(), true);
    EXPECT_EQ(m_q.getSize(), 4);
    EXPECT_EQ(m_q.isEmpty(), false);
    EXPECT_EQ(m_q.dequeue().payload, "");
    EXPECT_EQ(m_q.dequeue().payload, "dummy");
    EXPECT_EQ(m_q.dequeue().payload, "foo");
    mrroot501::Message<int> m1 = m_q.dequeue();
    EXPECT_EQ(m1.payload, "zombie");
    EXPECT_EQ(m1.header.timestamp, 3513515351);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
