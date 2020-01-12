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
    while(num > 0 ){
        std::cin>> val;
        vec.push_back(val);
        --num;
    }
    std::cin >> num;
   
    vec.erase(vec.begin()+num-1);
    int k, l;
    std::cin >>k >> l;
    vec.erase(vec.begin()+k-1, vec.begin()+l-1);
    std::cout<< vec.size() <<"\n";
    for(int i = 0; i < vec.size(); ++i){
      std::cout <<vec[i]<<" ";
    }
    return 0;
}
