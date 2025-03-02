//
// Created by Lenovo on 25-3-2.
//
#include "caseConvert.h"

bool caseConvert::isLowerCase(const char c) {
    return c >= 'a' && c <= 'z';
}

bool caseConvert::isUpperCase(const char c) {
    return c >= 'A' && c <= 'Z';
}

char caseConvert::toLowerCase(char c) {
    return isUpperCase(c) ? static_cast<char>(c + static_cast<int>('a' - 'A')) : c;
}

char caseConvert::toUpperCase(char c) {
    return isLowerCase(c) ? static_cast<char>(c - static_cast<int>('a' - 'A')) : c;
}

std::string caseConvert::reverseCase(const std::string& s) {
    std::stringstream ss;
    for (char c : s) {
        if (isLowerCase(c))
            ss << toUpperCase(c);
        else if (isUpperCase(c))
            ss << toLowerCase(c);
        else
            ss << c;
    }
    return ss.str();
}
