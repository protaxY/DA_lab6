#include "TBignumArithmetic.h"
#include <string>
#include <iostream>

int main(){
    NBignum::TBignumArithmetic a("1518507815185078");
    NBignum::TBignumArithmetic b("41736404173640");
    a = a - b;
    std::cout << a;
    return 0;
}