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
    int n;
    cin >> n;
    vector<int> height(n);
    int tallest = 0;
    int count = 0;
    for(int height_i = 0;height_i < n;height_i++){
       cin >> height[height_i];
       if(height[height_i] > tallest)
       {
          tallest =  height[height_i];
          count = 1;
       }
       else if (height[height_i] == tallest)
       {
           ++count;
       }
    }
    std::cout << count;
    return 0;
}
