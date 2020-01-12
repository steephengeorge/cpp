#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int num;
   std::cin >> num;
   if( num > 9)
   {
       std::cout << "Greater than 9\n";
       return 0;
   }
   switch(num){
       case 1:
             std::cout << "one\n";
             break;
       case 2: 
             std::cout << "two\n";
             break;
       case 3:
             std::cout << "three";
             break;
       case 4:
             std::cout << "four";
             break;
       case 5:
             std::cout << "five";
             break;
       case 6: 
             std::cout << "six";
             break;
       case 7: 
             std::cout << "seven";
             break;
       case 8:
             std::cout << "eight";
             break;
       case 9:
             std::cout << "nine"; 
             break;
   }
 
   return 0;
}
