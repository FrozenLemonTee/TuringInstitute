//
// Created by Lenovo on 25-2-24.
//
#include "times.h"

std::string time::eval(const int distance) {
    double walking_time = distance / 1.2;
    double bicycle_time = 27 + 23 + distance / 3.0;
    return std::abs(bicycle_time - walking_time) < 0.001 ? "一样快" : (bicycle_time < walking_time ? "骑车快" : "走路快");
}