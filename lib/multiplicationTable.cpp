//
// Created by Lenovo on 25-2-27.
//
#include "multiplicationTable.h"
#include "sstream"

std::vector<std::string> multiplicationTable::show() {
    std::vector<std::string> res;
    for (int i = 1; i <= 9; ++i) {
        std::stringstream ss;
        for (int j = 1; j <= i; ++j) {
            ss << j << " * " << i << " = " << i * j;
            if (i != j)
                ss << " ";
        }
        res.emplace_back(ss.str());
    }
    return res;
}
