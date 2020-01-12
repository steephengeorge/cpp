#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N ;
    std::cin >> N;
    std::unordered_map<std::string, int> vec;
    std::string input;
    while(N--)
    {       
        std::cin >> input;
        ++vec[input];     
    }
  
    int Q;
    std::cin >> Q;
    while(Q--)
    {
        std::string instr;
        std::cin >> instr;
        std::cout << vec[instr] << "\n";    
    }
    
}
