//
// Created by Lenovo on 25-2-26.
//
#include <gtest/gtest.h>
#include <sstream>
#include "avgAge.h"

// 测试avgAge构造函数和eval方法
TEST(AvgAgeTest, TestAvgAgeCalculation) {
    // 测试输入数据
    std::string input = "23\n25\n30\n22\n28\n";

    // 创建一个字符串流并将数据输入
    std::istringstream input_stream(input);

    // 创建avgAge对象
    avgAge ages(input_stream);

    // 计算平均年龄并验证
    std::string result = ages.eval();
    EXPECT_EQ(result, "25.60");  // 计算结果应为 25.6
}

TEST(AvgAgeTest, TestSingleElementInput) {
    // 测试只有一个年龄输入
    std::string input = "30";
    std::istringstream input_stream(input);

    avgAge ages(input_stream);

    // 如果只有一个元素，平均值应该等于该元素
    std::string result = ages.eval();
    EXPECT_EQ(result, "30.00");
}
