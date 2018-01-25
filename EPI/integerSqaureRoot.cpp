#include <iostream>
#include <vector>
//#include <algorithm>

int integerSquareRoot( const int k)
{
    int left = 0;
    int right = k;

    while( left <= right)
    {
        long mid = left + (right - left) / 2;
        long midSqaured = mid * mid;

        if( midSqaured <= k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
    }
    return left - 1;
}

int main() {
    std::cout << integerSquareRoot(37);

}