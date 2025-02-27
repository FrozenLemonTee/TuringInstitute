//
// Created by Lenovo on 25-2-26.
//
#include <gtest/gtest.h>
#include "rhombus.h"

// 测试：测试一个 3x3 的菱形
TEST(RhombusTest, TestSmallRhombus) {
    rhombus r(3);

    std::vector<std::string> expected = {
            "*",
            "***",
            "*****",
            "***",
            "*"
    };

    std::vector<std::string> result = r.show();

    EXPECT_EQ(result, expected);
}

// 测试：测试一个 5x5 的菱形
TEST(RhombusTest, TestMediumRhombus) {
    rhombus r(5);

    std::vector<std::string> expected = {
            "*",
            "***",
            "*****",
            "*******",
            "*********",
            "*******",
            "*****",
            "***",
            "*"
    };

    std::vector<std::string> result = r.show();

    EXPECT_EQ(result, expected);
}