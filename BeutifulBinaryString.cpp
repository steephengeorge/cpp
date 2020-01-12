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
    string B;
    cin >> B;
    const std::string pattern("010");
    auto found = B.find(pattern);
    int cnt = 0;
    while(found != std::string::npos){
        B[found+2]=1;
        ++cnt;
        found= B.find(pattern);        
    }
    
    
    
    /*if( found != std::string::npos){        
        ++cnt;
    }
    else{
        std::cout << 0;
        return 0;
    }
        
    while( found != std::string::npos){
     size_t found2;
     if( found+2 != std::string::npos )
         found2 = B.find(pattern, found+2);
     else{
         ++cnt;
         break;
     }
     if( found+2 == found2 ){
          found = found2;  
          continue;
     }        
     else
         ++cnt;
     found = found2;  
    }*/
    std::cout << cnt;
    return 0;
}
