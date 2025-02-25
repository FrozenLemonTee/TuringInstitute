//
// Created by Lenovo on 25-2-25.
//

#ifndef TURINGINSTITUTE_MATHS_H
#define TURINGINSTITUTE_MATHS_H

class maths{
public:
    template<class T>
    static const T& max(const T& a, const T& b, const T& c);
};

template<class T>
const T& maths::max(const T &a, const T &b, const T &c) {
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    return c;
}

#endif //TURINGINSTITUTE_MATHS_H
