#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

namespace NBignum{

const int BASE = 1000000;
const int RADIX_NUMBER = 6;

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
public:
    TBignumArithmetic() = default;
    TBignumArithmetic(std::string str);
    TBignumArithmetic(TBignumArithmetic &origin);
};

} // namespace NBignum


