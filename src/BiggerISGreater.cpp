#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    std::string s;
    std::cin >> n;
    while(n--){
        std::cin >> s; 
        std::string orig(s);      
        std::next_permutation(s.begin(),s.end()) ? 
                std::cout<<s<<"\n": std::cout<< "no answer\n";        
       
            
    }
    return 0;
}
