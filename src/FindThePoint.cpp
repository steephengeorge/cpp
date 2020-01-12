#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T = 0;
    std::cin >> T;
    while(T-- ){
        int x1, y1, x2, y2;
        std:cin >> x1 >> y1 >> x2 >> y2;
        std::cout << 2*x2 - x1 << " "<< 2*y2 - y1 << "\n"; 
        
    }
    return 0;
}
