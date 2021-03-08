#include "TBignumArithmetic.h"
#include <string>
#include <iostream>

int main(){
    NBignum::TBignumArithmetic a("2");
    NBignum::TBignumArithmetic b("10");
    a = a ^ b;
    std::cout << a;
    return 0;
}