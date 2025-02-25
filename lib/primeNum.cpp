//
// Created by Lenovo on 25-2-25.
//
#include "primeNum.h"

std::vector<int> primeNum::eval(int num) {
    std::vector<int> res;
    for (int i = 1; i <= num; ++i) {
        if (!notPrime(i))
            res.emplace_back(i);
    }
    return res;
}

bool primeNum::notPrime(int num) {
    if (num <= 1){
        return true;
    }
    for (int i = 2; i < num; i++){
        if (num % i == 0)
            return true;
    }
    return false;
}
