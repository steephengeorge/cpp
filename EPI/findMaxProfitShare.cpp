#include <iostream>
#include <vector>
#include <algorithm>

int findMaxProfit(std::vector<int> low, std::vector<int> high , std::vector<int> start)
{
    int maximum = std::numeric_limits<int>::min();
    for(size_t i =0; i < start.size()-1; ++i)
    {
        for(size_t j = i+1; j < start.size(); ++j)
        {
            maximum = std::max(maximum, start[j] - start[i]);

        }
    }
    return maximum;
}

int findMaxProfit(std::vector<int> start)
{
    int minimum =  start[0];
    int maximum = std::numeric_limits<int>::min();
    for(size_t i =1; i < start.size(); ++i)
    {
       minimum = std::min(minimum, start[i]);
       maximum = std::max(maximum, start[i] - minimum);
    }
    return maximum;
}

int main() {
     std::cout << findMaxProfit({1,2,3}, {2,3,4},{4,5,6,7})<< "\n";
     std::cout << findMaxProfit({4,5,6,7})<< "\n";
}