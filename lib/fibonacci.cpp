//
// Created by froze on 25-2-23.
//
#include "fibonacci.h"

int fibonacci::eval(const int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int f_n_minus_2 = 0;
    int f_n_minus_1 = 1;
    int f_n = 1;
    for (int i = 2; i <= n; i++)
    {
        f_n = f_n_minus_1 + f_n_minus_2;
        f_n_minus_2 = f_n_minus_1;
        f_n_minus_1 = f_n;
    }
    return f_n;
}
