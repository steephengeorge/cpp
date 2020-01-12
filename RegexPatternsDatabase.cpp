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
//#include <unordered_set>

using namespace std;


int main(){
    int N;
    cin >> N;
    std::vector<std::string> result;
    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        if( emailID.find("@gmail.com") == emailID.find_last_of("@") )
        {
            result.push_back(firstName);
        }
    }
    std::sort(result.begin(), result.end());
    for( auto&x : result){
        std::cout<< x<<"\n";
    }
    return 0;
}
