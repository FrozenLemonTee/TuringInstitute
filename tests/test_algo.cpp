//
// Created by Lenovo on 25-3-3.
//
#include "algo.h"
#include <gtest/gtest.h>

TEST(SwapTest, SwapValues) {
    int x = 5, y = 10;
    swaps(&x, &y);
    EXPECT_EQ(x, 10);
    EXPECT_EQ(y, 5);
}

TEST(SwapTest, SwapSameValues) {
    int x = 7, y = 7;
    swaps(&x, &y);
    EXPECT_EQ(x, 7);
    EXPECT_EQ(y, 7);
}

TEST(SwapTest, SwapZero) {
    int x = 0, y = 42;
    swaps(&x, &y);
    EXPECT_EQ(x, 42);
    EXPECT_EQ(y, 0);
}