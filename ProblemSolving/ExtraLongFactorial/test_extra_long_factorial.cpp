#include <gtest/gtest.h>
#include "extra_long_factorial.h"

TEST(TestExtraLongFactorial, tc1) {
    EXPECT_EQ(mrroot501::extraLongFactorial(0), "0");
    EXPECT_EQ(mrroot501::extraLongFactorial(1), "1");
    EXPECT_EQ(mrroot501::extraLongFactorial(20), "2432902008176640000");
    EXPECT_EQ(mrroot501::extraLongFactorial(27), "10888869450418352160768000000");
    EXPECT_EQ(mrroot501::extraLongFactorial(31), "8222838654177922817725562880000000");
}
