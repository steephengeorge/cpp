#include <iostream>
#include <vector>
#include <algorithm>


int maxSubArray(const std::vector<int> &A)
{


    int sum = A[0];
    int max = *(std::max_element( A.begin(), A.end()));

    //If all number are negative in the given vector
    if( max < 0)
      return max;

    max=A[0];

    for(size_t i =1; i< A.size(); ++i)
    {
        sum += A[i];
        if( sum < 0 )
        {
            sum = 0;
        }
        max= std::max(sum, max);

    }

    max= std::max(sum, max);
    return max;
}

int main()
{
    std::vector<int> X={-2, 1, -3, 4, -1, 2, 1, -5, 4 };

    std::cout<<maxSubArray(X);
}
