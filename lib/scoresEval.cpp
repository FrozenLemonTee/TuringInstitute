//
// Created by froze on 25-2-23.
//
#include "scoresEval.h"

int scoreSys::eval(const int nums_correct)
{
    if (nums_correct >= 0 && nums_correct <= 10)
    {
        return nums_correct * 6;
    }
    if (nums_correct >= 11 && nums_correct <= 20)
    {
        return 10 * 6 + (nums_correct - 10) * 2;
    }
    return 10 * 6 + 10 * 2 + (nums_correct - 10 - 10) * 1;
}
