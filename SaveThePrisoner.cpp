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
       int N, M, S;
       std::cin >> N >> M >> S;
       std::cout << (M+S-1-1)%N+1 <<"\n";
    }
    
    return 0;
}
