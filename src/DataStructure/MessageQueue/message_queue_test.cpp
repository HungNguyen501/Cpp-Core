#include <iostream>
#include <gtest/gtest.h>
#include "message_queue.h"
using namespace std;
using namespace mrroot501;

TEST(TestMessageQueue, tc1) {
    MessageQueue<Message<int>> mq = MessageQueue<Message<int>>(4, 3);
    EXPECT_EQ(mq.isEmpty(), true);
    EXPECT_EQ(mq.dequeue().isNull(), true);
    mq.enqueue(Message<int>(Header<int>(), "ab"));
    mq.enqueue(Message<int>(Header<int>(10), "c"));
    EXPECT_EQ(mq.length, 2);
    EXPECT_EQ(mq.byte_size, 3);
    mq.enqueue(Message<int>(Header<int>(10, 1717932438), "de"));
    EXPECT_EQ(mq.dequeue().payload, "ab");
    EXPECT_THROW(mq.enqueue(Message<int>(Header<int>(10, 1717932438), "defa")), std::invalid_argument);
    mq.enqueue(Message<int>(Header<int>(10, 1717932438), "de"));
    EXPECT_EQ(mq.length, 2);
    EXPECT_EQ(mq.dequeue().payload, "c");
    EXPECT_EQ(mq.front().payload, "de");
    EXPECT_EQ(mq.byte_size, 2);
    EXPECT_EQ(mq.dequeue().payload, "de");
    EXPECT_EQ(mq.byte_size, 0);
}

TEST(TestMessageQueue, testForcedEnqueue) {
    MessageQueue<Message<int>> mq2 = MessageQueue<Message<int>>(5, 20);
    EXPECT_THROW(mq2.enqueue(Message<int>(Header<int>(), "large_message_exception"), true), std::invalid_argument);
    mq2.enqueue(Message<int>(Header<int>(), "large_mess"), true);
    mq2.enqueue(Message<int>(Header<int>(), "large"), true);
    mq2.enqueue(Message<int>(Header<int>(), "message"), true);
    EXPECT_EQ(mq2.front().payload, "large");
    mq2.enqueue(Message<int>(Header<int>(), "write_large_message"), true);
    EXPECT_EQ(mq2.front().payload, "write_large_message");
    mq2.enqueue(Message<int>(Header<int>(), "m"), true);
    EXPECT_EQ(mq2.front().payload, "write_large_message");
    mq2.enqueue(Message<int>(Header<int>(), "e"), true);
    EXPECT_EQ(mq2.front().payload, "m");
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
