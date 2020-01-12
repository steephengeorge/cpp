#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <locale>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::string input;
    std::getline(std::cin, input);
    std::locale loc;
   
    int array[26]= {0};
    for( char &x : input )
    {
        if( isspace(x)|| isblank(x) || iscntrl(x) || ispunct(x))
            continue;
        x=std::tolower(x, loc);
        if ( !array[x -97])
        {           
            array[ x -97  ] = 1;
        }
    }
    if(std::accumulate( array , array+26, 0) == 26)
    {
        std::cout << "pangram\n";
        return 0 ;
    }
    std::cout << "not pangram\n";
   
    return 0;
}
