//
// Created by froze on 25-2-23.
//
#include <gtest/gtest.h>
#include "scoresEval.h"

TEST(ScoreSysTest, EvalTest) {
    // Test nums_correct between 0 and 10
    EXPECT_EQ(scoreSys::eval(0), 0);  // 0 * 6 = 0
    EXPECT_EQ(scoreSys::eval(5), 30); // 5 * 6 = 30
    EXPECT_EQ(scoreSys::eval(10), 60); // 10 * 6 = 60

    // Test nums_correct between 11 and 20
    EXPECT_EQ(scoreSys::eval(11), 62); // 10 * 6 + 1 * 2 = 60 + 2 = 62
    EXPECT_EQ(scoreSys::eval(15), 70); // 10 * 6 + 5 * 2 = 60 + 10 = 70
    EXPECT_EQ(scoreSys::eval(20), 80); // 10 * 6 + 10 * 2 = 60 + 20 = 80

    // Test nums_correct between 21 and 40
    EXPECT_EQ(scoreSys::eval(21), 81); // 10 * 6 + 10 * 2 + 1 * 1 = 60 + 20 + 1 = 81
    EXPECT_EQ(scoreSys::eval(23), 83); // 10 * 6 + 10 * 2 + 1 * 1 = 60 + 20 + 3 = 83
    EXPECT_EQ(scoreSys::eval(30), 90); // 10 * 6 + 10 * 2 + 10 * 1 = 60 + 20 + 10 = 90
    EXPECT_EQ(scoreSys::eval(40), 100); // 10 * 6 + 10 * 2 + 20 * 1 = 60 + 20 + 20 = 100
}