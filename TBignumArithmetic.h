#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

namespace NBignum{

const long BASE = 100000;
const int RADIX_NUMBER = 5;

class TBignumArithmetic {
private:
    std::vector<long> Bignum;
    friend std::ostream& operator<<(std::ostream &out, TBignumArithmetic num);
    friend bool operator==(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator>(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator>=(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator<(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator<=(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator+(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator-(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator*(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator*(TBignumArithmetic &lhs, long &rhs);
    friend TBignumArithmetic operator/(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator^(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
public:
    TBignumArithmetic() = default;
    TBignumArithmetic(std::string str);
    TBignumArithmetic(TBignumArithmetic &origin);
    TBignumArithmetic(TBignumArithmetic &&origin);
    TBignumArithmetic& operator=(TBignumArithmetic &other);
    TBignumArithmetic& operator=(TBignumArithmetic &&other);
};

} // namespace NBignum
