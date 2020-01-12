#include <iostream>
#include <cstdio>
#include <iomanip>

int main() {
    // Complete the code.
    int ival;
    long lval;
    long long llval;
    char cval;
    float fval;
    double dval;
    
    std::cin>>ival>>lval>>llval>>cval>>fval>>dval;
    std::cout<<std::setprecision(9)<<ival<<"\n";
    std::cout<<std::setprecision(9)<<lval<<"\n";
    std::cout<<std::setprecision(9)<<llval<<"\n";
    std::cout<<cval<<"\n";
    std::cout<<std::setprecision(9)<<fval<<"\n";
    std::cout<<std::setprecision(9)<<dval<<"\n";
    
    return 0;
}

