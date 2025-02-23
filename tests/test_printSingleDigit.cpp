//
// Created by froze on 25-2-23.
//

#include <gtest/gtest.h>

#include "printSingleDigit.h"


class SingleDigitTest : public testing::Test {
};

// 测试数字 0
TEST_F(SingleDigitTest, TestZero) {
    const std::vector<int> result = singleDigit::digits(0);
    const std::vector expected = {0, 0, 0};
    EXPECT_EQ(result, expected);
}

// 测试数字 1-9
TEST_F(SingleDigitTest, TestSingleDigits) {
    for (int i = 1; i <= 9; ++i) {
        std::vector<int> result = singleDigit::digits(i);
        std::vector expected = {0, 0, i};  // 比如 5 -> {0, 0, 5}
        EXPECT_EQ(result, expected);
    }
}

// 测试两位数 10-99
TEST_F(SingleDigitTest, TestDoubleDigits) {
    for (int i = 10; i <= 99; ++i) {
        std::vector<int> result = singleDigit::digits(i);
        std::vector<int> expected = {0, i / 10, i % 10};  // 比如 34 -> {0, 3, 4}
        EXPECT_EQ(result, expected);
    }
}

// 测试三位数 100-999
TEST_F(SingleDigitTest, TestTripleDigits) {
    for (int i = 100; i <= 999; ++i) {
        std::vector<int> result = singleDigit::digits(i);
        std::vector expected = {i / 100, i / 10 % 10, i % 10};  // 比如 345 -> {3, 4, 5}
        EXPECT_EQ(result, expected);
    }
}