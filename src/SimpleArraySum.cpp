#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
   std::string str;
   std::getline(std::cin, str);   
   std::getline(std::cin, str);
   
   int sum= 0;
   std::istringstream iss(str);
   int n;
   while( iss >> n )
   {
       sum += n;
   }
   std::cout<< sum;     

}
