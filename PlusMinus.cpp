#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int positive = 0;
    int negative = 0;
    int zeroes = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       if(arr[arr_i] > 0)
           ++positive;
       else if ( arr[arr_i] < 0 )
           ++negative;
       else
           ++zeroes;
    }
    std::cout<<std::fixed;
    std::cout<<std::setprecision(6);
    std::cout<< (double)positive/n << "\n";
    std::cout<< (double)negative/n << "\n";
    std::cout<< (double)zeroes / n <<"\n";
    
    return 0;
}
