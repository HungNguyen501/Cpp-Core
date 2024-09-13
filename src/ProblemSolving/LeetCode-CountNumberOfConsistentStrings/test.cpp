#include <iostream>
#include <vector>
#include <string>
#include "header.h"
#include <gtest/gtest.h>

TEST(TestCountConsistentStrings, tc1) {
    std::vector<std::vector<std::string>> word_inputs = {
        {"ad","bd","aaab","baa","badab"},
        {"a","b","c","ab","ac","bc","abc"},
        {"cc","acd","b","ba","bac","bad","ac","d"}
    };
    std::vector<std::string> allowed_inputs = {"ab", "abc", "cad"};
    int actuals[] = {2, 7, 4};
    // Run comparisons
    for (int i = 0; i < word_inputs.size(); i++) {
        EXPECT_EQ(countConsistentStrings(allowed_inputs[i], word_inputs[i]), actuals[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
