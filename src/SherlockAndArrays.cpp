#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
int accumulate_worker(T begin, T end )
{
    return std::accumulate( begin, end, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n;    
    
    while( n > 0)
    {   
        std::cin.tie(nullptr);
        int count;
        std::cin >> count;
        int l = count;
        int num = 0;
        std::vector< int> vec;
        vec.reserve(count);
        while( l > 0)
        {           
           std::cin >> num;
           vec.emplace_back(num);
           --l;
        }      
        if( count == 1)
        {
            std::cout << "YES\n";
            --n;
            continue;
        }
        num = 0;
        auto begin = vec.begin();
        auto end = vec.end();
        long long int result[count];
        std::partial_sum(begin,end, result);
 
        for(  ; num < count; ++num)
        {
            if( result[num] == result[count-1]- result[num+1])
            {
                std::cout << "YES\n";
                break;
            }           
        }       
        
        if( num == count)
        {
            std::cout << "NO\n";
        }
        n--;        
    }    
   
    return 0;
}
