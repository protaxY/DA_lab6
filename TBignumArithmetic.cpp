#include "TBignumArithmetic.h"

namespace NBignum{

TBignumArithmetic::TBignumArithmetic(std::string str) {
    for (long i = str.length(); i >= 0; i-=RADIX_NUMBER){
        if (i < RADIX_NUMBER){
            Bignum.push_back(atoi(str.substr(0, i).c_str()));
        } else {
            Bignum.push_back(atoi(str.substr(i - RADIX_NUMBER, RADIX_NUMBER).c_str()));
        }
    }
}

std::ostream &operator<<(std::ostream &out, TBignumArithmetic num) {
    if (num.Bignum.size() == 0){
        out << 0;
        return out;
    }
    out << num.Bignum[num.Bignum.size() - 1];
    for (long i = num.Bignum.size() - 2; i >= 0; --i){
        out << std::setw(RADIX_NUMBER) << std::setfill('0') << num.Bignum[i];
    }
    return out;
}

TBignumArithmetic::TBignumArithmetic(TBignumArithmetic &origin){
    for (long i = 0; i < origin.Bignum.size(); ++i){
        this->Bignum.push_back(origin.Bignum[i]);
    }
}

bool operator==(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    if (lhs.Bignum.size() != rhs.Bignum.size()){
        return false;
    }
    for (long i = 0; i < lhs.Bignum.size(); ++i){
        if (lhs.Bignum[i] != rhs.Bignum[i]){
            return false;
        }
    }
    return true;
}

bool operator>(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    if (lhs.Bignum.size() > rhs.Bignum.size()){
        return true;
    } else if (lhs.Bignum.size() < rhs.Bignum.size()){
        return false;
    } else {
        for (long i = lhs.Bignum.size(); i >= 0; --i) {
            if (lhs.Bignum[i] > rhs.Bignum[i]) {
                return true;
            } else if (lhs.Bignum[i] < rhs.Bignum[i]) {
                return false;
            }
        }
        return false;
    }
}

bool operator>=(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    if (lhs.Bignum.size() > rhs.Bignum.size()){
        return true;
    } else if (lhs.Bignum.size() < rhs.Bignum.size()){
        return false;
    } else {
        for (long i = lhs.Bignum.size(); i >= 0; --i) {
            if (lhs.Bignum[i] > rhs.Bignum[i]) {
                return true;
            } else if (lhs.Bignum[i] < rhs.Bignum[i]) {
                return false;
            }
        }
        return true;
    }
}

bool operator<(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    if (lhs.Bignum.size() < rhs.Bignum.size()){
        return true;
    } else if (lhs.Bignum.size() > rhs.Bignum.size()){
        return false;
    } else {
        for (long i = lhs.Bignum.size(); i >= 0; --i) {
            if (lhs.Bignum[i] < rhs.Bignum[i]) {
                return true;
            } else if (lhs.Bignum[i] > rhs.Bignum[i]) {
                return false;
            }
        }
        return false;
    }
}

bool operator<=(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    if (lhs.Bignum.size() < rhs.Bignum.size()){
        return true;
    } else if (lhs.Bignum.size() > rhs.Bignum.size()){
        return false;
    } else {
        for (long i = lhs.Bignum.size(); i >= 0; --i) {
            if (lhs.Bignum[i] < rhs.Bignum[i]) {
                return true;
            } else if (lhs.Bignum[i] > rhs.Bignum[i]) {
                return false;
            }
        }
        return true;
    }
}

TBignumArithmetic operator+(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    TBignumArithmetic res;
    long carry = 0;
    for (long i = 0; i < std::max(lhs.Bignum.size(), rhs.Bignum.size()); ++i){
        if (lhs.Bignum.size() <= i){
            res.Bignum.push_back(rhs.Bignum[i]);
        } else if (rhs.Bignum.size() <= i){
            res.Bignum.push_back(lhs.Bignum[i]);
        } else {
            res.Bignum.push_back(lhs.Bignum[i] + rhs.Bignum[i] + carry);
            carry = res.Bignum[i] / BASE;
            res.Bignum[i] %= BASE;
        }
    }
    if (carry){
        res.Bignum.push_back(carry);
    }
    return res;
}

TBignumArithmetic operator-(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    if (lhs < rhs){
        std::cout << "Error";
        return lhs;
    }
    TBignumArithmetic res(lhs);
    long carry = 0;
    for (long i = 0; i < rhs.Bignum.size(); ++i){
        res.Bignum[i] -= rhs.Bignum[i] + carry;
        if (res.Bignum[i] < 0){
            res.Bignum[i] += BASE;
            carry = 1;
        }
    }
    if (carry){
        res.Bignum[rhs.Bignum.size()] -= carry;
    }
    long i = res.Bignum.size() - 1;
    while (res.Bignum[i] == 0){
        res.Bignum.pop_back();
        --i;
    }
    return res;
}

TBignumArithmetic operator*(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
    TBignumArithmetic multiplier1;
    TBignumArithmetic multiplier2;
    TBignumArithmetic res;
    if (lhs >= rhs){
        multiplier1 = lhs;
        multiplier2 = rhs;
    } else {
        multiplier1 = rhs;
        multiplier2 = lhs;
    };
    long carry = 0;
    for (long i = 0; i < multiplier2.Bignum.size(); ++i){
        TBignumArithmetic term;
        for(long k = 0; k < i; ++k){
            term.Bignum.push_back(0);
        }
        carry = 0;
        for (long j = 0; j < multiplier1.Bignum.size(); ++j){
            term.Bignum.push_back(multiplier1.Bignum[j] * multiplier2.Bignum[i] + carry);
            carry = term.Bignum[term.Bignum.size() - 1] / BASE;
            term.Bignum[term.Bignum.size() - 1] %= BASE;
        }
        if (carry){
            term.Bignum.push_back(carry);
        }
        res = res + term;
    }
    return res;
}

} // namespace NBignum
