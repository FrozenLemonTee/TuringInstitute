//
// Created by Lenovo on 25-2-26.
//
#include <sstream>
#include <iomanip>
#include <numeric>
#include "avgAge.h"

avgAge::avgAge(std::istream &ipt) : ages() {
    std::string line;
    while (ipt >> line){
        this->ages.emplace_back(std::stoi(line));
    }
}

std::string avgAge::eval() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << std::accumulate(this->ages.begin(), this->ages.end(), 0) / static_cast<double>(this->ages.size());
    return ss.str();
}
