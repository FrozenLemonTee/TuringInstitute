//
// Created by froze on 25-2-28.
//
#include "movement.h"

#include <algorithm>

movement::movement(std::istream& ipt)
{
    std::string tmp;
    ipt >> tmp;
    this->element = std::vector<int>(std::stoi(tmp));
    for (auto& num : this->element)
    {
        ipt >> tmp;
        num = std::stoi(tmp);
    }
    ipt >> tmp;
    this->move = std::stoi(tmp);
}

void movement::moves()
{
    this->move %= static_cast<int>(this->element.size());
    std::reverse(this->element.begin(), this->element.begin() + (static_cast<int>(this->element.size()) - this->move));
    std::reverse(this->element.begin() + (static_cast<int>(this->element.size()) - this->move), this->element.end());
    std::ranges::reverse(this->element);
}

std::vector<int> movement::res() const
{
    return this->element;
}

