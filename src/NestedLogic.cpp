#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int exDay, exMonth, exYear;
    int reDay, reMonth, reYear;
 
    std::cin>> exDay >> exMonth >>exYear;
    std::cin >> reDay >> reMonth >> reYear;
    
    if(  exYear > reYear){
        std::cout<< 10000;
    }
    else if ( exMonth > reMonth &&  exYear == reYear){
        std::cout<< (exMonth - reMonth) * 500;
    }    
    else if( exDay > reDay && exMonth == reMonth &&  exYear == reYear){
        std::cout<< (exDay - reDay) * 15;
    }
    else
    {
        std::cout << 0;
    }
    
    return 0;
}
