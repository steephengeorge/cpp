#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n , d ;
    std::cin >> n >> d;
    std::vector<int> input;
    int num;
    while(n--)
    {
        std::cin >> num;
        input.push_back(num);
    }
    std::rotate(std::begin(input), input.begin()+d, input.end());
    for(const auto& ele: input)
    {
        std::cout << ele << " ";
    }
    return 0;
}
