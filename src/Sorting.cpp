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

int mySort(std::vector<int>& a){
 int swaps = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
    int numberOfSwaps = 0;
    
    for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            numberOfSwaps++;
        }
    }
    
    if (numberOfSwaps == 0) {
        break;
    }
    swaps += numberOfSwaps;
 }
 return swaps;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int swaps = mySort(a);
    std::cout<<"Array is sorted in "<<swaps <<" swaps.\n";
    std::cout<<"First Element: "<< a[0]<<"\n";
    std::cout<<"Last Element: "<<a[n-1]<<"\n";
    
    return 0;
}
