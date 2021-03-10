#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

namespace NBignum{
    const long BASE = 10000;
    const int RADIX_NUMBER = 4;

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

namespace NBignum{

    TBignumArithmetic::TBignumArithmetic(std::string str) {
        for (long i = str.length(); i > 0; i-=RADIX_NUMBER){
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

    TBignumArithmetic::TBignumArithmetic(TBignumArithmetic &&origin){
        for (long i = 0; i < origin.Bignum.size(); ++i){
            this->Bignum.push_back(origin.Bignum[i]);
        }
    }

    bool operator==(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
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
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
        if (lhs.Bignum.size() > rhs.Bignum.size()){
            return true;
        } else if (lhs.Bignum.size() < rhs.Bignum.size()){
            return false;
        } else {
            for (long i = lhs.Bignum.size() - 1; i >= 0; --i) {
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
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
        if (lhs.Bignum.size() > rhs.Bignum.size()){
            return true;
        } else if (lhs.Bignum.size() < rhs.Bignum.size()){
            return false;
        } else {
            for (long i = lhs.Bignum.size() - 1; i >= 0; --i) {
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
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
        if (lhs.Bignum.size() < rhs.Bignum.size()){
            return true;
        } else if (lhs.Bignum.size() > rhs.Bignum.size()){
            return false;
        } else {
            for (long i = lhs.Bignum.size() - 1; i >= 0; --i) {
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
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
        if (lhs.Bignum.size() < rhs.Bignum.size()){
            return true;
        } else if (lhs.Bignum.size() > rhs.Bignum.size()){
            return false;
        } else {
            for (long i = lhs.Bignum.size() - 1; i >= 0; --i) {
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
                res.Bignum.push_back(rhs.Bignum[i] + carry);
            } else if (rhs.Bignum.size() <= i){
                res.Bignum.push_back(lhs.Bignum[i] + carry);
            } else {
                res.Bignum.push_back(lhs.Bignum[i] + rhs.Bignum[i] + carry);
            }
            carry = res.Bignum[i] / BASE;
            res.Bignum[i] %= BASE;
        }
        if (carry){
            res.Bignum.push_back(carry);
        }
        long i = res.Bignum.size() - 1;
        while (i > 0 && res.Bignum[i] == 0){
            res.Bignum.pop_back();
            --i;
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
            carry = 0;
            if (res.Bignum[i] < 0){
                res.Bignum[i] += BASE;
                carry = 1;
            }
        }
        long k = rhs.Bignum.size();
        while (carry){
            res.Bignum[k] -= carry;
            carry = 0;
            if (res.Bignum[k] < 0){
                res.Bignum[k] += BASE;
                carry = 1;
            }
            ++k;
        }
        long i = res.Bignum.size() - 1;
        while (i > 0 && res.Bignum[i] == 0){
            res.Bignum.pop_back();
            --i;
        }
        return res;
    }

    TBignumArithmetic operator*(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
        TBignumArithmetic multiplier1(lhs);
        TBignumArithmetic multiplier2(rhs);
        TBignumArithmetic res;
        res.Bignum.resize(lhs.Bignum.size() + rhs.Bignum.size());
        long carry = 0;
        for (long i = 0; i < multiplier2.Bignum.size(); ++i){
            long term;
            carry = 0;
            for (long j = 0; j < multiplier1.Bignum.size(); ++j){
                term = rhs.Bignum[i] * lhs.Bignum[j] + res.Bignum[i + j] + carry;
                carry = term / BASE;
                res.Bignum[i + j] = term % BASE;
            }
            if (carry){
                res.Bignum[i + lhs.Bignum.size()] = carry;
            }
        }
        long i = res.Bignum.size() - 1;
        while (i > 0 && res.Bignum[i] == 0){
            res.Bignum.pop_back();
            --i;
        }
        return res;
    }

    TBignumArithmetic operator*(TBignumArithmetic &lhs, long &rhs) {
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        TBignumArithmetic res;
        long carry = 0;
        for (long i = 0; i < lhs.Bignum.size(); ++i){
            res.Bignum.push_back(lhs.Bignum[i] * rhs + carry);
            carry = res.Bignum[i] / BASE;
            res.Bignum[i] %= BASE;
        }
        if (carry){
            res.Bignum.push_back(carry);
        }
        long i = res.Bignum.size() - 1;
        while (i > 0 && res.Bignum[i] == 0){
            res.Bignum.pop_back();
            --i;
        }
        return res;
    }

    TBignumArithmetic operator/(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
        if (rhs.Bignum.size() == 0 || (rhs.Bignum.size() == 1 && rhs.Bignum[0] == 0)){
            std::cout << "Error";
            return lhs;
        }
        TBignumArithmetic res;
        TBignumArithmetic curDividend;
        for (int i = lhs.Bignum.size() - 1; i >= 0; --i){
            curDividend.Bignum.insert(curDividend.Bignum.begin(), lhs.Bignum[i]);
            if (curDividend < rhs){
                res.Bignum.push_back(0);
            } else {
                long l = 1;
                long r = BASE;
                long m;
                TBignumArithmetic tmp;
                while(l < r - 1){
                    m = (l + r) / 2;
                    tmp = rhs * m;
                    if (tmp <= curDividend){
                        l = m;
                    } else {
                        r = m;
                    }
                }
                tmp = rhs * l;
                curDividend = curDividend - tmp;
                res.Bignum.push_back(l);
            }
        }
        std::reverse(res.Bignum.begin(), res.Bignum.end());
        long i = res.Bignum.size() - 1;
        while (i > 0 && res.Bignum[i] == 0){
            res.Bignum.pop_back();
            --i;
        }
        return res;
    }

    TBignumArithmetic operator^(TBignumArithmetic &lhs, TBignumArithmetic &rhs) {
        while (lhs.Bignum.size() != 1 && lhs.Bignum[lhs.Bignum.size() - 1] == 0){
            lhs.Bignum.pop_back();
        }
        while (rhs.Bignum.size() != 1 && rhs.Bignum[rhs.Bignum.size() - 1] == 0){
            rhs.Bignum.pop_back();
        }
        if (rhs.Bignum.size() == 0 || (rhs.Bignum.size() == 1 && rhs.Bignum[0] == 0)){
            TBignumArithmetic res("1");
            return res;
        }
        TBignumArithmetic res("1");
        TBignumArithmetic big0("0");
        TBignumArithmetic big1("1");
        TBignumArithmetic big2("2");
        TBignumArithmetic tmp(lhs);
        while(rhs > big0){
            if (rhs.Bignum[0] % 2 == 1){
                res = res * tmp;
                rhs = rhs - big1;
            } else {
                tmp = tmp * tmp;
                rhs = rhs / big2;
            }
        }
        long i = res.Bignum.size() - 1;
        while (i > 0 && res.Bignum[i] == 0){
            res.Bignum.pop_back();
            --i;
        }
        return res;
    }

    TBignumArithmetic& TBignumArithmetic::operator=(TBignumArithmetic &other) {
        this->Bignum.clear();
        for (int i = 0; i < other.Bignum.size(); ++i){
            Bignum.push_back(other.Bignum[i]);
        }
        return *this;
    }

    TBignumArithmetic& TBignumArithmetic::operator=(TBignumArithmetic &&other) {
        this->Bignum.clear();
        for (int i = 0; i < other.Bignum.size(); ++i){
            Bignum.push_back(other.Bignum[i]);
        }
        return *this;
    }

} // namespace NBignum

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string str1, str2;
    char op;
    NBignum::TBignumArithmetic bigZero("0");
    while (std::cin >> str1 >> str2 >> op){
        NBignum::TBignumArithmetic lhs(str1);
        NBignum::TBignumArithmetic rhs(str2);
        if (op == '+'){
            std::cout << (lhs + rhs) << '\n';
        } else if (op == '-'){
            if (lhs < rhs){
                std::cout << "Error\n";
            } else {
                std::cout << (lhs - rhs) << '\n';
            }
        } else if (op == '*'){
            std::cout << (lhs * rhs) << '\n';
        } else if (op == '/'){
            if (rhs == bigZero){
                std::cout << "Error\n";
            } else {
                std::cout << (lhs / rhs) << '\n';
            }
        } else if (op == '^'){
            if (lhs == bigZero && rhs == bigZero){
                std::cout << "Error\n";
            } else {
                std::cout << (lhs ^ rhs) << '\n';
            }
        } else if (op == '='){
            if (lhs == rhs){
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        } else if (op == '>'){
            if (lhs > rhs){
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        } else if (op == '<'){
            if (lhs < rhs){
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        }
    }

    return 0;
}
