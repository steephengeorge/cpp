#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if( n <=1 )
        return false;
    if( n ==2 || n== 3)
        return true;
    int root = sqrt(n);
    for(int i = 2; i <= root; ++i)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    std::cin >> n;
    while(n--)
    {
        int num;
        std::cin >> num;
        std::cout<< ((isPrime(num))?"Prime\n":"Not prime\n");
    }
    return 0;
}
