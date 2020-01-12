#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int tests;
    std::cin >> tests;
    while(tests > 0)
    {
        std::string s;
        std::cin >> s;
        for(int i = 0; i < s.size(); i +=2)
        {
            std::cout<< s.at(i);    
        }
        std::cout<< " ";
        for(int i = 1; i < s.size(); i +=2)
        {
            std::cout<< s.at(i);    
        }
        std::cout<< "\n";
        --tests;
    }
    return 0;
}
