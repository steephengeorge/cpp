#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void bubbleSort(std::vector<int>& a)
{
    int numSwaps = 0;
    for(size_t i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a.size()-1; ++j)
        {
            if(a[j]> a[j+1])
            {
                ++numSwaps;
                std:swap(a[j], a[j+1]);
            }
        }
    }
    std::cout << "Array is sorted in " << numSwaps << " swaps.\n";    
}
int main() {
   int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    bubbleSort(a);
    std::cout << "First Element: "<<*a.begin()<<"\n";
    std::cout <<"Last Element: "<<*(--a.end())<<"\n";
  return 0;
}
