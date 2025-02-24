//
// Created by Lenovo on 25-2-24.
//
#include <gtest/gtest.h>
#include "times.h"

TEST(TimeTest, HandlesDistanceComparison) {
    struct TestCase {
        int distance;
        std::string expected;
    };

    // 定义测试用例
    TestCase testCases[] = {
            {1, "走路快"},
            {10, "走路快"},
            {33, "走路快"},
            {100, "一样快"},
            {110, "骑车快"}
    };

    for (const auto& [distance, expected] : testCases) {
        EXPECT_EQ(time::eval(distance), expected)
                            << "Failed for distance = " << distance;
    }
}