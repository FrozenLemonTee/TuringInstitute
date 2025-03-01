//
// Created by froze on 25-3-1.
//
#include "func.h"
#include <cstdio>

int* fun() {
    const auto a = new int[4]{3, 4, 5, 6};
    return a;
}

void main_func()
{
    const int *b = fun();
    const auto c = new int[4];
    printf("%d", b[0]);
    delete[] c;
    delete[] b;
}
