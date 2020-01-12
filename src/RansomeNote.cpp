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
#include <set>

using namespace std;

bool ransom_note(const vector<string>& magazine, const vector<string> ransom) {
    std::map<string, int> magazineMap;
    
    for(const auto& word: magazine)
    {
        magazineMap[word]++;
    }
    
    for( const auto& ele: ransom)
    {
        auto found = magazineMap.find(ele);
        if( found !=  magazineMap.end() )
        {
            if(found->second > 0)
            {
                magazineMap[ele]--;
            }
            else
            {
                //std::cout << "No";
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
