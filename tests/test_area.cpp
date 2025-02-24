//
// Created by Lenovo on 25-2-24.
//

#include <gtest/gtest.h>
#include "areaDiff.h"
#include <cmath>
#include <string>

TEST(AreaTest, DiffTest) {
    // 测试范围：length 从 1 到 999
    for (int length = 1; length < 1000; ++length) {
        // 预期结果：面积差 = length^2 - (0.5 * length)^2 * PI
        double expected_diff = std::pow(length, 2) - std::pow(0.5 * length, 2) * 3.14;

        // 调用 diff 方法并解析结果
        std::string result_str = area::diff(length);
        double result = std::stod(result_str); // 将返回值转换为 double

        // 误差容忍度：小于等于 0.01
        EXPECT_NEAR(result, expected_diff, 0.01);
    }
}