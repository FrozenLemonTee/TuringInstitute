//
// Created by Lenovo on 25-2-24.
//
#include "sequence.h"

int sequence::eval(const int n, const int a) {
    int sum_n = 0;
    int f_n = a;
    for (int i = 0; i < n; ++i) {
        sum_n += f_n;
        f_n = f_n * 10 + a;
    }
    return sum_n;
}