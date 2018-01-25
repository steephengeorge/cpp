#include <iostream>
#include <vector>
#include <algorithm>

short countNumberOfBits(unsigned int x)
{
    short numOfBits = 0;
    while(x)
    {
        numOfBits += x&1;
        x >>= 1;
    }
    return numOfBits;
}
int main() {
    std::cout << countNumberOfBits(5);
}