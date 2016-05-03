#include <iostream>
#include <set>
#include <vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<limits>

using namespace std;    

int maxSubArray(const vector<int> &A)
{
    
    
    int sum=A[0];
    int max= *(std::max_element( A.begin(), A.end()));
    
    if( max < 0)
      return max;
    max=A[0];
     
    
    for(unsigned int i =1; i< A.size(); ++i)
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
