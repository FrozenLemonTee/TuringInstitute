//
// Created by froze on 25-2-28.
//
#include "matrix.h"

#include <istream>

matrix::matrix(std::istream& ipt)
{
    std::string tmp;
    ipt >> tmp;
    this->length = std::stoi(tmp);
    this->m = std::vector<std::vector<int>>(this->length);
    for (int i = 0; i < this->length; ++i)
    {
        this->m[i] = std::vector<int>(this->length);
        for (int j = 0; j < this->length; ++j)
        {
            ipt >> tmp;
            this->m[i][j] = std::stoi(tmp);
        }
    }
}

std::vector<std::vector<int>> matrix::getMatrix() const
{
    return this->m;
}

std::vector<std::vector<int>> matrix::rotateView() const
{
    std::vector<std::vector<int>> res(this->length);
    for (int i = 0; i < this->length; ++i)
    {
        res[i] = std::vector<int>(this->length);
        for (int j = 0; j < this->length; ++j)
        {
            res[i][j] = this->m[this->length - 1 - j][i];
        }
    }
    return res;
}
