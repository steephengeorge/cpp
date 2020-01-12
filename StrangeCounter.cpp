#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    long long t;
    cin >> t;
   long long cycle = 3;
   int prev = 1;
   long long sum = 3;
  
    while( t > sum  ){                  
        cycle = 2 * cycle;       
        sum += cycle ;      
    }
    std::cout << sum - t +1;
    return 0;
}
