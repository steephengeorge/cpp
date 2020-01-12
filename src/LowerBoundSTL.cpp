#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    std::cin >> n;
    int num;
    std::vector<int> vec;
    while(n > 0){
        std::cin >> num;
        vec.push_back(num);
        --n;
    }
    std::cin >> n;
    while( n > 0){
        std::cin >> num;
        auto low = std::lower_bound(vec.begin(),vec.end(), num);
        if(*low == num){
            std::cout<<"Yes"<< " "<<std::distance(vec.begin(), low)+1<<"\n";
        }
        else{
            std::cout<<"No"<< " "<<std::distance(vec.begin(), low)+1<<"\n";
        } 
        --n;
    }
    return 0;
}
