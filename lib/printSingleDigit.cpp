//
// Created by froze on 25-2-23.
//
#include "printSingleDigit.h"

#include <algorithm>

std::vector<int> singleDigit::digits(const int num)
{
    std::vector res = {0, 0, 0};
    int num_ = num;
    for (auto& digit : res)
    {
        digit = num_ % 10;
        num_ /= 10;
    }
    std::ranges::reverse(res);
    return res;
}
