//
// Created by froze on 25-2-28.
//
#include "matrix.h"
#include <gtest/gtest.h>
#include <sstream>

class MatrixTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 初始化测试数据：构造一个 3x3 的矩阵
        std::string input = "3\n1 2 3\n4 5 6\n7 8 9";  // 输入: 长度为 3，矩阵元素
        std::istringstream ss(input);
        testMatrix = new matrix(ss);
    }

    void TearDown() override {
        delete testMatrix;
    }

    matrix* testMatrix{};
};

// 测试构造函数是否正确解析输入
TEST_F(MatrixTest, ConstructorTest) {
    std::vector<std::vector<int>> expected = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    EXPECT_EQ(testMatrix->getMatrix(), expected);  // 假设你有一个 getter 来获取矩阵
}

// 测试 rotateView 方法是否正确旋转矩阵
TEST_F(MatrixTest, RotateViewTest) {
    const std::vector<std::vector<int>> expected = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    EXPECT_EQ(testMatrix->rotateView(), expected);  // 旋转后的矩阵应该是预期的结果
}

// 测试 transpositionView 方法是否正确执行矩阵转置
TEST_F(MatrixTest, TranspositionViewTest) {
    const std::vector<std::vector<int>> expected = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    EXPECT_EQ(testMatrix->transpositionView(), expected);
}