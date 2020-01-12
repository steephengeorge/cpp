#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int input;
    std::cin >> input;
    std::bitset<64> num(input);
   
  
    int cnt = 0;
    int result = 0;
    for(size_t i = 0 ; i< num.size(); ++i)
    {
        if(num.test(i)){
            ++cnt;            
        }
        else{
            if( cnt >  result)
                result = cnt;
            cnt = 0;
        }            
    }
    std::cout << result;
    return 0;
}
