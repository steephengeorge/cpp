#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int num;
    std::cin >> num;
    std::vector<int> vec;
    int val;
    while( std::cin >> val){
        vec.push_back(val);        
    }
    for( int i = num-1; i >=0; --i)
    {
        std::cout<< vec[i]<<" ";
    }
    return 0;
}
