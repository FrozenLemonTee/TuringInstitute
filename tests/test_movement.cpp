//
// Created by froze on 25-2-28.
//
#include "movement.h"
#include <gtest/gtest.h>
#include <sstream>

class MovementTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 设置默认的测试输入流
        const std::string input = "5\n1 2 3 4 5\n3";  // 第一个数字是大小，后面是元素，最后是移动数
        std::istringstream ss(input);
        testMovement = new movement(ss);
    }

    void TearDown() override {
        delete testMovement;
    }

    movement* testMovement{};
};

// 测试构造函数是否正确解析输入
TEST_F(MovementTest, ConstructorTest) {
    const std::vector expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(testMovement->res(), expected);
}

// 测试 moves 方法是否正确工作
TEST_F(MovementTest, MovesTest) {
    testMovement->moves();
    const std::vector expected = {3, 4, 5, 1, 2};  // 根据给定的移动数（3），期望的结果是 {3, 4, 5, 1, 2}
    EXPECT_EQ(testMovement->res(), expected);
}