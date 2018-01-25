#include <iostream>
#include <vector>
#include <algorithm>

short parity(unsigned long x)
{
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    return x & 0x1;
}

int main()
{
    std::cout << "    " <<parity(4);

}