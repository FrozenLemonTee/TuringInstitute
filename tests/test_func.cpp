//
// Created by froze on 25-3-1.
//
#include <string>
#include <gtest/gtest.h>
#include "func.h"

TEST(MainFuncTest, BasicExecution) {
    testing::internal::CaptureStdout();  // 捕获标准输出
    main_func();
    const std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "3");  // 期待输出 "3"
}