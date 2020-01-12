#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int count = 0;
    std::cin >> count;
    std::map<std::string, long long> book;
    std::string name;
    long long number;
    while( count > 0){
        
        std::cin >> name >> number;
        book[name]= number;
        --count;        
    }
    while ( std::cin >> name )
    {
        if( book.find(name) != book.end())
        {
            std::cout << name;
            std::cout<< "=";
            std::cout<< (book.find(name))->second<<"\n";
            continue;
        }
        std::cout<<"Not found\n";
     }
    return 0;
}
