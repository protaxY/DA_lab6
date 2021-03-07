#include "TBignumArithmetic.h"
#include <string>
#include <iostream>

int main(){
    NBignum::TBignumArithmetic a("15185078178");
    NBignum::TBignumArithmetic b("41736400");
    a = a * b;
    std::cout << a;
    return 0;
}