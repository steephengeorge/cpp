#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int l = 0;
    int r = 0;
    std::cin >> l;
    std::cin >> r;
    
    int p = l^r;
    
    int count = 0;
    while(p)
    {
       ++count;
        p >>= 1;
    }
    std::cout << std::pow(2, count) -1;
    return 0;
}
