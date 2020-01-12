#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int tests = 0;
    std::cin >> tests;
    while(tests > 0){
        int arraySize;
        std::cin >>arraySize;
       
        
        long long nonConResult = 0;
        long long conResult = -10001;
        
        long long sum = 0;
        
       
        while( arraySize > 0){             
            int num;
            std::cin >> num;            
            sum += num;
            
            if( sum > conResult )  
            {
                conResult = sum;                
            }
            if( sum < 0 )
            {
                sum = 0;
            }    
           
            
           
            
            if( num < 0 &&  nonConResult == 0)
            {
                nonConResult = num;
            }
            else if( nonConResult + num > nonConResult )
            {
                nonConResult += num;
            } 
            if( nonConResult < num )
            {
                nonConResult = num;
            }
            --arraySize;
        }
               
        std::cout << conResult << " "<<nonConResult<<"\n";
        --tests;
    }
    return 0;
}
