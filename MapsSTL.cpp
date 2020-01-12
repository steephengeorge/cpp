#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    std::cin >> n;
    int x, y;
    std::map<std::string, int> dir;
    std::string name;
    while(n > 0){\
       
        std::cin >> x ;
        switch(x){
            case 1:
                  std::cin>> name >> y;
                  dir[name] +=  y;
                  break;
            case 2:
                  std::cin>> name;
                  dir.erase(name);
                  break;
            case 3:
                   std::cin>> name;
                   auto found = dir.find(name);
                   if( found != dir.end()){
                       std::cout<<found->second<<"\n"; 
                   }
                   else {
                       std::cout<<0<<"\n";
                   }
                   break;
        }
        --n;
    }
    return 0;
}
