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
    while( std::cin >> num){
        vec.push_back(num);
    }
    std::sort(vec.begin(), vec.end());
    for(auto&x: vec){
        std::cout <<x<<" ";
    }
    return 0;
}
