#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int  fac(int n, int result){
    if( n <= 1)
        return result;
    return fac( n-1, result * n);    
}

int factorial( int n){
    return fac(n, 1);
}
    

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    std::cin >> n;
    std::cout<<factorial(n);
    return 0;
}
