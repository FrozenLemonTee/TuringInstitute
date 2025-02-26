//
// Created by Lenovo on 25-2-26.
//
#include "rhombus.h"
#include "string"

rhombus::rhombus(int size) : size_(size) {}

std::vector<std::string> rhombus::show() const {
    std::vector<std::string> res;
    for (int i = 1; i <= this->size_; i++){
        res.emplace_back(2 * i - 1, '*');
    }
    for (int i = this->size_ - 1; i > 0; i--){
        res.emplace_back(2 * i - 1, '*');
    }
    return res;
}
