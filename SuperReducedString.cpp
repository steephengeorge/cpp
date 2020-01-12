#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::string text;
    std::cin >> text;
    auto it =  std::adjacent_find(text.begin(), text.end());
    do{
        if(it != text.end()){
            it = text.erase(it, ++(it+1));
        }
        else {
            break;      
        }
        it = std::adjacent_find(text.begin(), text.end());
   } while( 1);
   text.empty()? std::cout <<"Empty String" :  std::cout << text;
   
   return 0;
}
