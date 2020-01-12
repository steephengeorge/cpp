#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n , k;
    std::cin >> n >>k;
    std::vector<int> vec;
    while( n--){
        int number;
        std::cin >> number;
        vec.push_back(number);
    }
    int mx = *std::max_element(vec.begin(), vec.end());
    int result = 0;
    if( mx > k)
        result = mx-k;
        
    std::cout << result;
    
}
