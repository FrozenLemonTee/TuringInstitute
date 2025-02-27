//
// Created by Lenovo on 25-2-27.
//
#include "gtest/gtest.h"
#include "merge.h"  // 包含 merge 类定义

// 测试 mergeResult 方法
TEST(MergeTest, BasicMerge) {
    // 创建一个输入流，模拟文件输入
    std::istringstream input("3 3\n1 3 5\n2 4 6");

    // 使用输入流初始化 merge 类
    merge m(input);

    // 调用 mergeResult 获取合并后的结果
    std::vector<int> result = m.mergeResult();

    // 定义预期的结果
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};

    // 使用 ASSERT_EQ 判断结果
    ASSERT_EQ(result, expected);
}

TEST(MergeTest, EmptyLeftSequence) {
    std::istringstream input("0 3\n\n2 4 6");
    merge m(input);
    std::vector<int> result = m.mergeResult();
    std::vector<int> expected = {2, 4, 6};
    ASSERT_EQ(result, expected);
}

TEST(MergeTest, EmptyRightSequence) {
    std::istringstream input("3 0\n1 3 5\n");
    merge m(input);
    std::vector<int> result = m.mergeResult();
    std::vector<int> expected = {1, 3, 5};
    ASSERT_EQ(result, expected);
}

TEST(MergeTest, EqualElements) {
    std::istringstream input("3 3\n1 1 1\n1 1 1");
    merge m(input);
    std::vector<int> result = m.mergeResult();
    std::vector<int> expected = {1, 1, 1, 1, 1, 1};
    ASSERT_EQ(result, expected);
}

TEST(MergeTest, ReverseOrder) {
    std::istringstream input("3 3\n1 3 5\n2 4 6");
    merge m(input);
    std::vector<int> result = m.mergeResult();
    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    ASSERT_EQ(result, expected);
}