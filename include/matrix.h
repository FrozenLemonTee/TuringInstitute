//
// Created by froze on 25-2-28.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
#include <vector>

class matrix
{
    std::vector<std::vector<int>> m;
    int length;
public:
    explicit matrix(std::istream& ipt);

    [[nodiscard]] std::vector<std::vector<int>> getMatrix() const;

    [[nodiscard]] std::vector<std::vector<int>> rotateView() const;
};

#endif //MATRIX_H
