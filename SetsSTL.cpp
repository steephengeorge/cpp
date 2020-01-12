#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    std::cin >> n;
    int x, y;
    std::set<int> vec;
    while( n > 0){
        std::cin >> x >> y;
        switch(x){
            case 1:
                   vec.insert(y);
                   break;
            case 2:
                   vec.erase(y);
                   break;
            case 3:
                   if( vec.find(y) != vec.end()){
                       std::cout<<"Yes\n";
                   }
                   else{
                       std::cout<<"No\n";
                   }
                   break;
                   
        }
        --n;
    }
    return 0;
}
