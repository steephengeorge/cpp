#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    int n;
    std::cin >> n;
    
    std::string s;
    //std::getline(std::cin, s);
    //std::cout<<s;
    //std::istringstream iss(s);
    std::vector<int> vec;
    int num;
    while( std::cin >> num )
    {
        vec.push_back(num);        
    }
    
    num = vec[n - 1];
    int i = 1;
    
    
    while( i <= n )
    {
        vec[n - i] = vec[n- i -1];       
       
        if ( vec[n - i -1] <= num )
        {
            vec[n-i] = num;
            for ( auto& x : vec)
            {
                std::cout<< x<< " ";
            }
            std::cout << "\n";
            break;                
        } 
        for ( auto& x : vec)
        {
            std::cout<< x<< " ";
        }
        std::cout << "\n";
        ++i;
        
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
