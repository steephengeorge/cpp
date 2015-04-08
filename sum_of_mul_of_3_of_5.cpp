#include <iostream>

int main()
{
    // 3 + 6 +....+999 = 3 ( 1 + 2+ ...+333) =3 * ( 333 * 334)
    unsigned int sum_mult_3_upto_1000  =  3 * 333 * 334 >> 1;
    unsigned int sum_mult_5_upto_1000  =  5 * 199 * 200 >> 1;
    unsigned int sum_mult_15_upto_1000 =  15 * 67 * 66  >> 1;

    unsigned sum = sum_mult_3_upto_1000 + 
                   sum_mult_5_upto_1000 - sum_mult_15_upto_1000;
    std::cout<< sum <<"\n";
}
