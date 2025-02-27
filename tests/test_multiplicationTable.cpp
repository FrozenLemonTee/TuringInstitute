//
// Created by Lenovo on 25-2-27.
//
#include "gtest/gtest.h"
#include "multiplicationTable.h"

TEST(MultiplicationTableTest, ShowTest) {
    // 直接通过类名调用静态方法 show()
    std::vector<std::string> result = multiplicationTable::show();

    // 检查返回的行数
    ASSERT_EQ(result.size(), 9);

    // 检查每一行的内容
    ASSERT_EQ(result[0], "1 * 1 = 1");
    ASSERT_EQ(result[1], "1 * 2 = 2 2 * 2 = 4");
    ASSERT_EQ(result[2], "1 * 3 = 3 2 * 3 = 6 3 * 3 = 9");
    ASSERT_EQ(result[3], "1 * 4 = 4 2 * 4 = 8 3 * 4 = 12 4 * 4 = 16");
    ASSERT_EQ(result[4], "1 * 5 = 5 2 * 5 = 10 3 * 5 = 15 4 * 5 = 20 5 * 5 = 25");
    ASSERT_EQ(result[5], "1 * 6 = 6 2 * 6 = 12 3 * 6 = 18 4 * 6 = 24 5 * 6 = 30 6 * 6 = 36");
    ASSERT_EQ(result[6], "1 * 7 = 7 2 * 7 = 14 3 * 7 = 21 4 * 7 = 28 5 * 7 = 35 6 * 7 = 42 7 * 7 = 49");
    ASSERT_EQ(result[7], "1 * 8 = 8 2 * 8 = 16 3 * 8 = 24 4 * 8 = 32 5 * 8 = 40 6 * 8 = 48 7 * 8 = 56 8 * 8 = 64");
    ASSERT_EQ(result[8], "1 * 9 = 9 2 * 9 = 18 3 * 9 = 27 4 * 9 = 36 5 * 9 = 45 6 * 9 = 54 7 * 9 = 63 8 * 9 = 72 9 * 9 = 81");
}