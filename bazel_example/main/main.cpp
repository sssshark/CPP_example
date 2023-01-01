#include "module/add_func.h"

#include "mul_func.h"

#include "div_func.h"


int main() {


    int a = 10;
    int b = 2;

    int add_res = add(a, b);
    int mul_res = multiply(a, b);
    int div_res = division(a, b);

    std::cout<<add_res<<" "<< mul_res << " " << div_res <<std::endl;
    return 0;
}