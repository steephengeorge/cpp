#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long N, M;
    std::cin >> N >> M;
    std::vector<long long> vec(N,0);  

    while(M--)
    {
        unsigned long long a,b,k;
        std::cin >> a >> b >> k;
       
        vec[a-1] += k;
        if(b < N)
            vec[b] -= k;
    }  
    long long max = 0;
    long long cumulative = 0;
    for(long long i = 0; i < N ; ++i)
    {
        cumulative += vec[i];
        if( cumulative > max)
            max = cumulative;
    }
    std::cout << max;
}
