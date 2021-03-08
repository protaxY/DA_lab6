#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

namespace NBignum{

const long BASE = 10;
const int RADIX_NUMBER = 1;

class TBignumArithmetic {
private:
    std::vector<long> Bignum;
//    friend TBignumArithmetic& operator=(TBignumArithmetic&& expr);
    friend std::ostream& operator<<(std::ostream &out, TBignumArithmetic num);
    friend bool operator==(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator>(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator>=(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator<(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend bool operator<=(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator+(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator-(const TBignumArithmetic lhs, const TBignumArithmetic rhs);
    friend TBignumArithmetic operator*(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator*(TBignumArithmetic &lhs, long &rhs);
    friend TBignumArithmetic operator/(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
    friend TBignumArithmetic operator^(TBignumArithmetic &lhs, TBignumArithmetic &rhs);
public:
    TBignumArithmetic() = default;
    TBignumArithmetic(std::string str);
    TBignumArithmetic(TBignumArithmetic &origin);
};

} // namespace NBignum


