#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    while( 1){
        if(arr.size() <= 1)
             break;
        std::cout<< arr.size()<<"\n";
        int min = *std::min_element(arr.begin(), arr.end());
        for(auto&x : arr){ x -=min;}             
        arr.erase(std::remove(arr.begin(),arr.end(), 0),arr.end());
    }
    if( arr.size() > 0)
      std::cout<< arr.size()<<"\n";
    return 0;
}
