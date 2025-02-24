//
// Created by Lenovo on 25-2-24.
//
#include <gtest/gtest.h>
#include "sequence.h"

TEST(SequenceTest, HandlesNAndA) {
    struct TestCase {
        int n;
        int a;
        int expected;
    };

    TestCase testCases[] = {
            {2, 1, 1 + 11},  // n = 2, a = 1 -> 1 + 11
            {2, 2, 2 + 22},  // n = 2, a = 2 -> 2 + 22
            {3, 1, 1 + 11 + 111}, // n = 3, a = 1 -> 1 + 11 + 111
            {3, 2, 2 + 22 + 222}, // n = 3, a = 2 -> 2 + 22 + 222
            {4, 1, 1 + 11 + 111 + 1111}, // n = 4, a = 1 -> 1 + 11 + 111 + 1111
            {4, 3, 3 + 33 + 333 + 3333},  // n = 4, a = 3 -> 3 + 33 + 333 + 3333
            {5, 4, 4 + 44 + 444 + 4444 + 44444}, // n = 5, a = 4 -> 4 + 44 + 444 + 4444 + 44444
            {6, 5, 5 + 55 + 555 + 5555 + 55555 + 555555}, // n = 6, a = 5 -> 5 + 55 + 555 + 5555 + 55555 + 555555
    };

    for (const auto& [n, a, expected] : testCases) {
        EXPECT_EQ(sequence::eval(n, a), expected)
                            << "Failed for n = " << n << " and a = " << a;
    }
}