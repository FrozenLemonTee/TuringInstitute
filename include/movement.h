//
// Created by froze on 25-2-28.
//

#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <istream>
#include <vector>

class movement
{
    std::vector<int> element;
    int move{};
public:
    explicit movement(std::istream& ipt);

    void moves();

    [[nodiscard]] std::vector<int> res() const;
};

#endif //MOVEMENT_H
