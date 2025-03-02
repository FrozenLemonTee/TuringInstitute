//
// Created by Lenovo on 25-3-2.
//
#include "PascalsTriangle.h"
#include <gtest/gtest.h>

TEST(PascalsTriangleTest, GenerateTriangle) {
    EXPECT_EQ(PascalsTriangle::show(0), std::vector<std::vector<int>>{});
    EXPECT_EQ(PascalsTriangle::show(1), (std::vector<std::vector<int>>{{1}}));
    EXPECT_EQ(PascalsTriangle::show(2), (std::vector<std::vector<int>>{{1}, {1, 1}}));
    EXPECT_EQ(PascalsTriangle::show(3), (std::vector<std::vector<int>>{{1}, {1, 1}, {1, 2, 1}}));
    EXPECT_EQ(PascalsTriangle::show(4), (std::vector<std::vector<int>>{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}}));
    EXPECT_EQ(PascalsTriangle::show(5), (std::vector<std::vector<int>>{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}));
}