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

int number_needed(string a, string b) {
    //std::transform(a.begin(), a.end(), a.begin(), ::tolower); 
    //std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    int aArray[26];
    int bArray[26];
        
    for(int i = 0; i < 26; ++i)
    {
        aArray[i] = 0;
    }    
    for(int i = 0; i < 26; ++i)
    {
        bArray[i] = 0;
    }
    
    for(const auto& x: a)
    {
        aArray[x-'a']++;
    }
    
    for(const auto& x: b)
    {
        bArray[x-'a']++;
    }
    int count = 0;
    for(int i = 0; i < 26; ++i)
    {
        //a==3 b ==4
        if( aArray[i] != bArray[i])
        {
            count += std::abs(aArray[i]-bArray[i]);   
            //count += aArray[i] +bArray[i]-2*std::min(aArray[i], bArray[i]);
        }
    }
    return count;    
    
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
