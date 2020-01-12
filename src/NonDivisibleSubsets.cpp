#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int k, n;
    std::cin >> n >> k;
    if(k == 1){
        std::cout<<1;
        return 0;
    }
    std::vector<int> vec;
    int num;
    while(n--){
        std::cin >> num;
        vec.push_back(num);
    }
    int karr[k];
    for(int i =0; i < k; ++i){
        karr[i] = 0;
    }
  
    for( auto& x: vec){
        karr[x%k]++;
    }
    
   
    int cnt =0;
    
    for(int i =1; i < k/2; ++i){
        if(karr[i]  < karr[k-i]){           
            cnt += karr[k-i];            
        }
        else{            
            cnt += karr[i];           
        }        
    }
   
    if( k%2 != 0 ){
        int i= k/2;
        if(karr[i]  < karr[k-i]){           
            cnt += karr[k-i];            
        }
        else{ 
              cnt += karr[i];           
        }        
        
    }
    if( (k%2 == 0) && (karr[k/2] > 0)){
        ++cnt;
    }
    
   
    if(karr[0] > 0){       
        ++cnt;
    }
    
    std::cout << cnt;
    return 0;
}
