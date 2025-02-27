//
// Created by Lenovo on 25-2-27.
//
#include "merge.h"

merge::merge(std::istream &ipt) {
    std::string size_l, size_r;
    ipt >> size_l >> size_r;
    this->left = std::vector<int>(std::stoi(size_l));
    this->right = std::vector<int>(std::stoi(size_r));
    for (int& i : this->left) {
        std::string s;
        ipt >> s;
        i = std::stoi(s);
    }
    for (int& j : this->right) {
        std::string s;
        ipt >> s;
        j = std::stoi(s);
    }
}

std::vector<int> merge::mergeResult() const {
    int i = 0, j = 0;
    std::vector<int> res;
    while (i < this->left.size() && j < this->right.size()){
        if (this->left[i] <= this->right[j]){
            res.emplace_back(this->left[i]);
            i += 1;
        } else{
            res.emplace_back(this->right[j]);
            j += 1;
        }
    }

    while (i < this->left.size()){
        res.emplace_back(this->left[i]);
        i += 1;
    }
    while (j < this->right.size()){
        res.emplace_back(this->right[j]);
        j += 1;
    }
    return res;
}
