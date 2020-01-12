#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N , Q ;
    std::cin >> N >> Q;
    int lastAns = 0;
    std::vector<std::vector<int>> seq(N, std::vector<int>());
    
    while(Q--)
    {
       int type, x, y;
       std::cin >> type >> x >> y;
       int index = 0;
       switch(type)
       {
           case 1:           
              index = (x ^ lastAns) % N;
              seq[index].push_back(y);
              break;
           case 2: 
               index = (x ^ lastAns) % N;
               lastAns = seq[index] [y % seq[index].size()];
               std::cout << lastAns << "\n";
               break;           
       }
    }
}
