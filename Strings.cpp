#include <iostream>
#include <string>
#include <algorithm>
//using namespace std;

int main() {
   // Complete the program
   std::string first, second;
   std::cin >> first >> second;
   std::cout << first.length() << " " << second.length()<<"\n";
   std::cout << first+second<<"\n";
   char temp =  first[0];
   first[0] = second[0];
   second[0] = temp;
  
   std::cout << first << " "<< second;
   
  
    return 0;
}
