//
// Created by froze on 25-2-23.
//
#include <gtest/gtest.h>
#include "fibonacci.h"

TEST(FibonacciTest, HandlesRange3To29) {
    struct TestCase {
        int n;
        int expected;
    };
    TestCase testCases[] = {
        {3, 2},
        {4, 3},
        {5, 5},
        {6, 8},
        {7, 13},
        {8, 21},
        {9, 34},
        {10, 55},
        {11, 89},
        {12, 144},
        {13, 233},
        {14, 377},
        {15, 610},
        {16, 987},
        {17, 1597},
        {18, 2584},
        {19, 4181},
        {20, 6765},
        {21, 10946},
        {22, 17711},
        {23, 28657},
        {24, 46368},
        {25, 75025},
        {26, 121393},
        {27, 196418},
        {28, 317811},
        {29, 514229}
    };

    for (const auto& [n, expected] : testCases) {
        EXPECT_EQ(fibonacci::eval(n), expected)
            << "Failed at n = " << n;
    }
}