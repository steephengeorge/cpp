#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    bool odd = N % 2 != 0  ? 1 : 0;
    if( odd)
    {
        std::cout <<"Weird\n";
    }
    else if( N >= 2 && N <= 5 )
    {
         std::cout <<"Not Weird\n";
    }
    else if ( N>=6 && N <= 20)
    {
        std::cout <<"Weird\n";
    }
    else if(  N > 20 )
    {
        std::cout <<"Not Weird\n";
    }
    return 0;
}
