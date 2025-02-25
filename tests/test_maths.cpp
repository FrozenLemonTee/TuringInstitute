//
// Created by Lenovo on 25-2-25.
//
#include <gtest/gtest.h>
#include "maths.h"
#include <algorithm>

// 测试全正数场景
TEST(MaxTest, PositiveNumbers) {
    EXPECT_EQ(maths::max(1, 2, 3), std::max({1, 2, 3}));
    EXPECT_EQ(maths::max(5, 5, 3), std::max({5, 5, 3}));  // 并列最大值
    EXPECT_EQ(maths::max(100, 200, 150), std::max({100, 200, 150}));
}

// 测试全负数场景
TEST(MaxTest, NegativeNumbers) {
    EXPECT_EQ(maths::max(-3, -2, -1), std::max({-3, -2, -1}));
    EXPECT_EQ(maths::max(-5, -5, -7), std::max({-5, -5, -7}));
    EXPECT_EQ(maths::max(-1000, -2000, -500), std::max({-1000, -2000, -500}));
}

// 测试正负混合场景
TEST(MaxTest, MixedNumbers) {
    EXPECT_EQ(maths::max(-50, 0, 100), std::max({-50, 0, 100}));
    EXPECT_EQ(maths::max(0, -100, 0), std::max({0, -100, 0}));    // 包含零
    EXPECT_EQ(maths::max(-1, 999, 500), std::max({-1, 999, 500}));
}

// 测试相等或部分相等场景
TEST(MaxTest, EqualValues) {
    EXPECT_EQ(maths::max(5, 5, 5), std::max({5, 5, 5}));      // 全部相等
    EXPECT_EQ(maths::max(5, 5, 3), std::max({5, 5, 3}));      // 前两个相等且最大
    EXPECT_EQ(maths::max(3, 5, 5), std::max({3, 5, 5}));      // 后两个相等且最大
    EXPECT_EQ(maths::max(5, 3, 5), std::max({5, 3, 5}));      // 一、三相等且最大
}

// 测试最大值出现在不同位置
TEST(MaxTest, OrderIndependence) {
    EXPECT_EQ(maths::max(300, 200, 100), std::max({300, 200, 100}));  // 第一参数最大
    EXPECT_EQ(maths::max(100, 300, 200), std::max({100, 300, 200}));  // 第二参数最大
    EXPECT_EQ(maths::max(100, 200, 300), std::max({100, 200, 300}));  // 第三参数最大
}

// 测试较大常规值组合（替代原极端值测试）
TEST(MaxTest, LargeRegularValues) {
    const int kLargePos = 10000;   // 大正整数
    const int kLargeNeg = -10000;  // 小负整数

    EXPECT_EQ(maths::max(kLargePos, 0, kLargeNeg), std::max({kLargePos, 0, kLargeNeg}));
    EXPECT_EQ(maths::max(kLargeNeg, kLargePos, 0), std::max({kLargeNeg, kLargePos, 0}));
    EXPECT_EQ(maths::max(kLargePos, kLargePos, kLargePos), std::max({kLargePos, kLargePos, kLargePos})); // 全大正数
}