#include <iostream>
#include <string>
#include <vector>
#include<algorithm>


using namespace std;    

vector<int> wave(vector<int> &A) {
    std::sort(std::begin(A), std::end(A));
    if(A.size() % 2 ==0)
    {
       for( int i = 0; i < A.size() ; i+=2)
       {
          std::swap(A[i], A[i+1]);
       }
    }
    else
    {
        for( int i = 0; i < A.size()-1 ; i+=2)
       {
          std::swap(A[i], A[i+1]);
       }
    }
    return A;
}

int main()
{
    std::vector<int> X={ 5, 1, 3, 2, 4};
    wave(X);
    for ( auto &x : X)
     std::cout<<x<<" ";
         
}
