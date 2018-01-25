#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

void evenOdd(std::vector<int>* input)
{
    std::vector<int>& vec = *input;
    int next_even = 0;
    int next_odd = vec.size() - 1;

    for(size_t i = 0; i < vec.size(); ++i)
    {
        if(vec[i] % 2 == 0)
        {
            ++next_even;
        }
        else
        {
            std::swap(vec[i], vec[next_odd--]);
        }
    }
}

int main()
{



}