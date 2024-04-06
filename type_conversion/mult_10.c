#include "strnum.h"
long int power_10(const int num, const int exponent){
    const int base = 10;
    long int number = 1;
    for (int i = 0; i < exponent; i++){
        number *= base;
    }
    number *= num;
    return number;
}

double power_neg10(const int num, const int exponent){
    const float base = 10;
    float number = 1;
    for (int i = 0; i < exponent; i++){
        number /= 10;
    }
    number *= num;
    return number;
}
