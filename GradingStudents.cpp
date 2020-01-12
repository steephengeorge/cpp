#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; 
    std::cin >> n; 
    int grade;
    while(n--)
    {
        std::cin >> grade;
        if( grade < 38)
        {
            std::cout << grade << "\n";
        }
        else
        {
            int numberOfFive = grade / 5;
            int upper = (numberOfFive + 1) * 5;
            
            if( upper - grade < 3 )
            {
                std::cout << upper << "\n";
            }
            else
            {
                std::cout << grade << "\n";
            }
        }
    }
    return 0;
}
