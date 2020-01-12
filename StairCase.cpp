#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    int j = 1;
    while( j <=n)
    {
       
       std::cout << std::setw (n-j+1);
       std::cout << std::setfill (' ') ;
       int i = j;
       while( i > 0)
       {
           std::cout<<"#";
           --i;
       }
       std::cout<<"\n";
       ++j;
    }
    return 0;
}
