#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    std::cin >> T;
    while(T--){
        std::string s;
        std::cin >> s;
        int cnt=0;
        char prev;
        for(auto it = s.begin(); it != s.end(); ++it){
            if( it == s.begin()){
                prev= *it;
                continue;
            }
            if( prev == *it){                
                ++cnt;
                continue;
            }
            prev = *it;
        }
        std::cout << cnt<<"\n";
    }
    return 0;
}
