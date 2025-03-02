//
// Created by Lenovo on 25-3-2.
//
#include "PascalsTriangle.h"

std::vector<std::vector<int>> PascalsTriangle::show(size_t lines) {
    std::vector<std::vector<int>> res;
    for (size_t i = 1; i <= lines; i++){
        std::vector<int> l(i);
        for (size_t j = 1; j <= i; j++){
            if (j == 1 || j == i){
                l[j - 1] = 1;
            } else{
                l[j - 1] = res[res.size() - 1][j - 2] + res[res.size() - 1][j - 1];
            }
        }
        res.emplace_back(l);
    }
    return res;
}
