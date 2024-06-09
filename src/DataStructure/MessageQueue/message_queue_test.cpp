#include <iostream>
#include <gtest/gtest.h>
#include "message_queue.h"
using namespace std;
using namespace mrroot501;

TEST(TestMessageQueue, tc1) {
    MessageQueue<int> mq = MessageQueue<int>(4, 3);
    EXPECT_EQ(mq.isEmpty(), true);
    EXPECT_EQ(mq.dequeue().isNull(), true);
    mq.enqueue(Message<int>(Header<int>(), "ab"));
    mq.enqueue(Message<int>(Header<int>(10), "c"));
    EXPECT_EQ(mq.length, 2);
    EXPECT_EQ(mq.byte_size, 3);
    mq.enqueue(Message<int>(Header<int>(10, 1717932438), "de"));
    EXPECT_EQ(mq.dequeue().payload, "ab");
    mq.enqueue(Message<int>(Header<int>(10, 1717932438), "defg"));
    mq.enqueue(Message<int>(Header<int>(10, 1717932438), "de"));
    EXPECT_EQ(mq.length, 2);
    EXPECT_EQ(mq.dequeue().payload, "c");
    EXPECT_EQ(mq.front().payload, "de");
    EXPECT_EQ(mq.byte_size, 2);
    EXPECT_EQ(mq.dequeue().payload, "de");
    EXPECT_EQ(mq.byte_size, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
