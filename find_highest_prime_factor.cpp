#include <iostream>
//What is the largest prime factor of the number 600851475143 ?
#include <vector>
#include<algorithm>
#include<chrono>

int main()
{
    auto start = std::chrono::steady_clock::now();
    std::ios_base::sync_with_stdio(false);
    long num=600851475143;
    std::vector<long> devisorList;
    long d=2;
    while(num > 1)
    {
         if (num%d ==0)
         {
            devisorList.emplace_back(d);
            num/=d;
         }
         ++d;
    }
    auto gpf=std::max_element(devisorList.begin(), devisorList.end());
    std::cout<<"gpf:"<< *gpf <<std::endl;
    auto end = std::chrono::steady_clock::now();
    auto duration= std::chrono::duration_cast<std::chrono::microseconds>(end-start);
   std::cout<< duration.count()<<std::endl;
   return 0;
}
