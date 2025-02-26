//
// Created by Lenovo on 25-2-26.
//

#ifndef TURINGINSTITUTE_RHOMBUS_H
#define TURINGINSTITUTE_RHOMBUS_H

#include <vector>
#include <wsman.h>
#include "string"

class rhombus{
    int size_;
public:
    explicit rhombus(int size);

    [[nodiscard]] std::vector<std::string> show() const;
};

#endif //TURINGINSTITUTE_RHOMBUS_H
