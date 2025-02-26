//
// Created by Lenovo on 25-2-26.
//

#ifndef TURINGINSTITUTE_AVGAGE_H
#define TURINGINSTITUTE_AVGAGE_H
#include "string"
#include "vector"

class avgAge{
    std::vector<int> ages;
public:
    explicit avgAge(std::istream& ipt);

    std::string eval() const;
};

#endif //TURINGINSTITUTE_AVGAGE_H
