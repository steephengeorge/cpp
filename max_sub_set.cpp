#include <iostream>
#include <string>
#include <vector>
#include<algorithm>


using namespace std;    

vector<int> maxset(vector<int> &A) {

    std::vector<int  > result;
    std::vector<int > temp;
    long long sum = 0;
    long long  max = 0;
    long long result_max=0;
    for( auto& x: A)
    {
        
        sum += x;            
       
        if( sum >= max)
        {
            max = sum;            
            temp.push_back(x);
        }
         if( sum < max)
        {          
            if( max >=  result_max )
            {
               result_max = max;
               result.clear();
               std::copy(std::begin(temp), std::end(temp), std::back_inserter(result));
               temp.clear();
            }
           // 
            temp.clear();            
            sum = 0;
            max = 0;
           
            //temp.push_back(x);
        }
    }
    if( max >  result_max )
    {
       result_max = max;
       result.clear();
       std::copy(std::begin(temp), std::end(temp), std::back_inserter(result));       
    }
    
    return result;
}
int main()
{
    std::vector<int > X= { 24115, -75629, -46517, 30105, 19451, -82188, 99505, 6752, -36716, 54438, -51501, 83871, 11137, -53177, 22294, -21609, -59745, 53635, -98142, 27968, -260, 41594, 16395, 19113, 71006, -97942, 42082, -30767, 85695, -73671 };
   
    std::vector<int> re=maxset(X);
    for( auto& ele: re)
    {
        std::cout<<ele<<",";
    }
}
