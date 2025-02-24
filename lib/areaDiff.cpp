//
// Created by Lenovo on 25-2-24.
//
#include <sstream>
#include <iomanip>
#include "areaDiff.h"
#include "cmath"

std::string area::diff(const int length) {
    constexpr double PI = 3.14;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2)
    << std::pow(length, 2) * 1.0 - std::pow(0.5 * length, 2) * PI;
    return ss.str();
}