#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n=0;
    std::cin >> n;
    while(n--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        if(std::abs(z-x) > std::abs(z-y))
        {
            std::cout << "Cat B\n";
        }
        else if(std::abs(z-x) < std::abs(z-y))
        {
            std::cout << "Cat A\n";
        }
        else
        {
            std::cout << "Mouse C\n";
        }
        
    }
    return 0;
}
