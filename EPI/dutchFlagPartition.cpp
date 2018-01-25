#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using color = enum {RED, WHITE, BLUE};

void dutchFlagPartition(std::vector<color>* input, int pivotIndex)
{
    std::vector<color>& vec = *input;
    color pivot = vec[pivotIndex];

    int smaller = 0;
    int larger = vec.size() - 1;

    for(size_t i = 0; i < vec.size(); ++i)
    {
        if( vec[i] < pivot)
        {
            std::swap(vec[i], vec[smaller++]);
        }
    }

    for(size_t i = vec.size() - 1; i >= 0; --i)
    {
        if(vec[i] > pivot)
        {
            std::swap(vec[i], vec[larger--]);
        }
    }
}

int main()
{



}