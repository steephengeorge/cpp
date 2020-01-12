#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;


int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    int firstDiag = 0;
    for(int a_i = 0, a_j = 0 ;a_i < n && a_j < n ;++a_i, ++a_j )
    {
        firstDiag+= a[a_i][a_j];
    }
    
    int secondDiag = 0;
    for(int a_i = 0, a_j = n-1 ;a_i < n && a_j >= 0  ;++a_i, --a_j )
    {
        secondDiag+= a[a_i][a_j];
    }
    
    std::cout<< std::abs(firstDiag - secondDiag );
    return 0;
}
