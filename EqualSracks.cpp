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
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
    }
    int first = std::accumulate(h1.begin(), h1.end(), 0);
    int second = std::accumulate(h2.begin(),h2.end(),0);
    int third = std::accumulate(h3.begin(),h3.end(), 0);
    while(1){
        
        if( first == second  && second == third )
            break;
        
        if( first > second){
            
            first -= h1.front();
            //std::cout<<"first:"<<first<<"\n";
            h1.erase(h1.begin());
            //h1.pop_back();            
        }
        else if( second > first){
            
            second -=h2.front();
            //std::cout<<"second:"<<second<<"\n";
            h2.erase(h2.begin());
        }
        else if( first > third){
            first -= h1.front();
            //std::cout<<"first:"<<first<<"\n";
            h1.erase(h1.begin());
        }
        else if( third > first){
            
            third -= h3.front();
            //std::cout<<"third:"<<third<<"\n";
            h3.erase(h3.begin());
        }
        else if(third > second ){
            third -=h3.front();
            //std::cout<<"third:"<<third<<"\n";
            h3.erase(h3.begin());
        }
        else if(second > third){
            
            second -=h2.front();
            //std::cout<<"second:"<<second<<"\n";
            h2.erase(h2.begin());
        }
    }
    std::cout << first;
    return 0;
}
