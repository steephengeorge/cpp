#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num = 0;
    std::cin>>num;
    while( num > 0){
        int cnt =0;
        std::cin >> cnt;
        if( cnt == 1){
             std::cout << "Not prime\n";
             --num;
             continue;             
        }
            
        int temp = std::sqrt(cnt);
        bool flag = false;
        int i = 2;
        while ( i <= temp){
            if( cnt % i == 0)
            {
                std::cout << "Not prime\n";
                flag = true;
                break;
            }
            ++i;
        }
        if (!flag)
        {
            std::cout <<"Prime\n";
        }
        --num;
    }
    return 0;
}
