#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    std::cin >> n;
    int lonely = 0;
    int num = 0;
    while(n--)
    {
        std::cin >> num;
        lonely ^= num;
    }
    std::cout << lonely;
    return 0;
}
