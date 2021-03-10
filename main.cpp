#include "TBignumArithmetic.h"

int main(){
    std::string str;
    NBignum::TBignumArithmetic bigZero("0");
    while (std::cin >> str){
        NBignum::TBignumArithmetic lhs(str);
        std::cin >> str;
        NBignum::TBignumArithmetic rhs(str);
        char op;
        std::cin >> op;
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