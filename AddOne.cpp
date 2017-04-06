
#include <iostream>
#include <vector>
#include<algorithm>

// Add one to a big number
std::vector<int> plusOne(std::vector<int> &A)
{

    std::reverse(std::begin(A), std::end(A) );
    std::vector<int> result;
    int carry=1;

    for(size_t i =0; i < A.size(); ++i)
    {
        int val = A[i] + carry;
        carry= (val) / 10;
        if(  carry > 0)
        {
            result.push_back( (A[i] + carry) % 10);
            carry= (A[i] + carry) / 10;
            continue;
        }
        result.push_back(val);
    }
    if( carry > 0)
    {
        result.push_back(carry);
    }



    std::reverse(std::begin(result), std::end(result) );
    auto it = std::find_if( std::begin(result), std::end(result),
                             [](int i){return i >= 1;});
    if( it != std::end(result))
    {
        result.erase(std::begin(result), it);
    }
    return result;
}

int main()
{
    std::vector<int> X={1, 1, 1, 3, 2, 1, 1, 2, 5, 9, 6, 5};
    std::vector<int> A = plusOne(X);
    for( auto& ele: A)
    {
        std::cout<< ele;
    }
}
