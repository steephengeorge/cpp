#include <iostream>

int countBits( unsigned int x)
{
    int numBits = 0;
    while(x)
    {
        x >>= 1;
        ++numBits;
    }
    return numBits;
}

int main()
{
   std::cout<< countBits(1);
}
