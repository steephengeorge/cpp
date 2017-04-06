#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> createWave(std::vector<int> &A) {
    std::sort(std::begin(A), std::end(A));
    if(A.size() % 2 ==0)
    {
       for( size_t i = 0; i < A.size() ; i+=2)
       {
          std::swap(A[i], A[i+1]);
       }
    }
    else
    {
        for( size_t i = 0; i < A.size()-1 ; i+=2)
       {
          std::swap(A[i], A[i+1]);
       }
    }
    return A;
}

int main()
{
    std::vector<int> X={ 5, 1, 3, 2, 4,7};
    createWave(X);
    for ( auto &x : X)
       std::cout<<x<<" ";
}
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> createWave(std::vector<int> &A) {
    std::sort(std::begin(A), std::end(A));
    if(A.size() % 2 ==0)
    {
       for( size_t i = 0; i < A.size() ; i+=2)
       {
          std::swap(A[i], A[i+1]);
       }
    }
    else
    {
        for( size_t i = 0; i < A.size()-1 ; i+=2)
       {
          std::swap(A[i], A[i+1]);
       }
    }
    return A;
}

int main()
{
    std::vector<int> X={ 5, 1, 3, 2, 4,7};
    createWave(X);
    for ( auto &x : X)
       std::cout<<x<<" ";
}
