//
// Created by Lenovo on 25-2-25.
//
#include <gtest/gtest.h>
#include "primeNum.h"

class PrimeNumTest : public ::testing::Test {
};

// 测试 num 为负数的情况，期望返回空向量
TEST_F(PrimeNumTest, NegativeInput) {
    std::vector<int> result = primeNum::eval(-1);
    EXPECT_TRUE(result.empty());
}

// 测试 num 为 0 的情况，期望返回空向量
TEST_F(PrimeNumTest, ZeroInput) {
    std::vector<int> result = primeNum::eval(0);
    EXPECT_TRUE(result.empty());
}

// 测试 num 为 1 的情况，期望返回空向量，因为 1 不是质数
TEST_F(PrimeNumTest, OneInput) {
    std::vector<int> result = primeNum::eval(1);
    EXPECT_TRUE(result.empty());
}

// 测试 num 为 2 的情况，期望返回包含 2 的向量，因为 2 是质数
TEST_F(PrimeNumTest, TwoInput) {
    std::vector<int> result = primeNum::eval(2);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 2);
}

// 测试 num 为 10 的情况，期望返回质数向量 {2, 3, 5, 7}
TEST_F(PrimeNumTest, TenInput) {
    std::vector<int> result = primeNum::eval(10);
    std::vector<int> expected = {2, 3, 5, 7};
    EXPECT_EQ(result, expected);
}

// 测试 num 为 100 的情况，检查是否返回正确的质数
TEST_F(PrimeNumTest, HundredInput) {
    std::vector<int> result = primeNum::eval(100);
    std::vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    EXPECT_EQ(result, expected);
}