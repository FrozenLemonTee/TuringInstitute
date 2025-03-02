//
// Created by Lenovo on 25-3-2.
//
#include "caseConvert.h"
#include <gtest/gtest.h>

TEST(CaseConvertTest, IsLowerCase) {
    EXPECT_TRUE(caseConvert::isLowerCase('a'));
    EXPECT_TRUE(caseConvert::isLowerCase('z'));
    EXPECT_FALSE(caseConvert::isLowerCase('A'));
    EXPECT_FALSE(caseConvert::isLowerCase('Z'));
    EXPECT_FALSE(caseConvert::isLowerCase('0'));
    EXPECT_FALSE(caseConvert::isLowerCase('#'));
}

TEST(CaseConvertTest, IsUpperCase) {
    EXPECT_TRUE(caseConvert::isUpperCase('A'));
    EXPECT_TRUE(caseConvert::isUpperCase('Z'));
    EXPECT_FALSE(caseConvert::isUpperCase('a'));
    EXPECT_FALSE(caseConvert::isUpperCase('z'));
    EXPECT_FALSE(caseConvert::isUpperCase('9'));
    EXPECT_FALSE(caseConvert::isUpperCase('&'));
}

TEST(CaseConvertTest, ToLowerCase) {
    EXPECT_EQ(caseConvert::toLowerCase('A'), 'a');
    EXPECT_EQ(caseConvert::toLowerCase('Z'), 'z');
    EXPECT_EQ(caseConvert::toLowerCase('a'), 'a');
    EXPECT_EQ(caseConvert::toLowerCase('z'), 'z');
    EXPECT_EQ(caseConvert::toLowerCase('1'), '1');
    EXPECT_EQ(caseConvert::toLowerCase('$'), '$');
}

TEST(CaseConvertTest, ToUpperCase) {
    EXPECT_EQ(caseConvert::toUpperCase('a'), 'A');
    EXPECT_EQ(caseConvert::toUpperCase('z'), 'Z');
    EXPECT_EQ(caseConvert::toUpperCase('A'), 'A');
    EXPECT_EQ(caseConvert::toUpperCase('Z'), 'Z');
    EXPECT_EQ(caseConvert::toUpperCase('3'), '3');
    EXPECT_EQ(caseConvert::toUpperCase('@'), '@');
}

TEST(CaseConvertTest, ReverseCase) {
    EXPECT_EQ(caseConvert::reverseCase("Hello"), "hELLO");
    EXPECT_EQ(caseConvert::reverseCase("WORLD"), "world");
    EXPECT_EQ(caseConvert::reverseCase("gOoD dAy"), "GoOd DaY");
    EXPECT_EQ(caseConvert::reverseCase("123!@#"), "123!@#");
    EXPECT_EQ(caseConvert::reverseCase(""), "");
}
