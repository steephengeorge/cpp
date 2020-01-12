#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

//ing namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    std::ios_base::sync_with_stdio(false);
    int n, s , p, q;
    std::cin >> n>>s>>p>>q;
   
    std::vector<int> vec(n);
    
    vec[0] = s & 2147483647;      
    for( int i = 1; i <= n-1; ++i){
        vec[i]= ((vec.at(i-1)*p)+q) & (2147483647);        
    }  
    //std::sort(vec.begin(), vec.end());
    auto it= std::unique(vec.begin(), vec.end());    
   
    std::cout << std::distance(vec.begin(), it);    
    
    return 0;
}
