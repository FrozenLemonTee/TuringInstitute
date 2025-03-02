//
// Created by Lenovo on 25-3-2.
//

#ifndef TURINGINSTITUTE_CASECONVERT_H
#define TURINGINSTITUTE_CASECONVERT_H
#include <sstream>

class caseConvert{
public:
    static bool isLowerCase(char c);

    static bool isUpperCase(char c);

    static char toLowerCase(char c);

    static char toUpperCase(char c);

    static std::string reverseCase(const std::string& s);
};

#endif //TURINGINSTITUTE_CASECONVERT_H
