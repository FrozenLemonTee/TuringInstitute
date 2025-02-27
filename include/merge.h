//
// Created by Lenovo on 25-2-27.
//

#ifndef TURINGINSTITUTE_MERGE_H
#define TURINGINSTITUTE_MERGE_H
#include "vector"
#include "string"

class merge{
    std::vector<int> left;
    std::vector<int> right;
public:
    explicit merge(std::istream& ipt);

    [[nodiscard]] std::vector<int> mergeResult() const;
};

#endif //TURINGINSTITUTE_MERGE_H
