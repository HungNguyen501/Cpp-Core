#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::string extraLongFactorial(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    std::string result = "";
    std::vector<int> factorial;
    factorial.push_back(2);
    for (int i = 3; i <= n; i++) {
        int tempScore = 0;
        for (int j = 0; j < factorial.size(); j++) {
            tempScore = factorial[j] * i + tempScore;
            factorial[j] = tempScore % 10;
            tempScore /= 10;

            if (j == factorial.size() - 1 && tempScore > 0) {
                factorial.push_back(tempScore);
                break;
            }
        }
    }
    for (int i = factorial.size() - 1; i >= 0; i--) {
        result += std::to_string(factorial[i]);
    }
    return result;
}

TEST(TestExtraLongFactorial, tc1) {
    EXPECT_EQ(extraLongFactorial(0), "0");
    EXPECT_EQ(extraLongFactorial(1), "1");
    EXPECT_EQ(extraLongFactorial(20), "2432902008176640000");
    EXPECT_EQ(extraLongFactorial(27), "10888869450418352160768000000");
    EXPECT_EQ(extraLongFactorial(31), "8222838654177922817725562880000000");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
