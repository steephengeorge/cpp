#include <iostream>
#include <vector>
#include <algorithm>

short parity( unsigned long x)
{
    short result = 0;
    while(x)
    {
        result ^= (x&1);
        x >>= 1;
    }
    return result;
}


int main()
{
    std::cout << "    " <<parity(3);

}