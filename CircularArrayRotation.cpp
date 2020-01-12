#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    //std::ios_base::sync_with_stdio(false);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<int> vec;
    int num;
    while( n--){
        std::cin >> num;
        vec.push_back(num);
    }
    if( k > vec.size())
        k= k % vec.size();
    
    std::rotate(vec.rbegin(), vec.rbegin()+k, vec.rend());
   
      
        
    while( q--){
      std::cin >> num;
      std::cout << vec[num]<<"\n";
    }
    return 0;
}
