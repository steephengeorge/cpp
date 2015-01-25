#include<iostream>
//Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms
int main()
{
   long first=1;
   long second=2;
   long sum=2;
   while(1 )
   {
    
      first+=second;
      second+=first;
      if(first%2==0 && first < 4000000 )
         sum+=first;
      if(second%2==0 && second < 4000000)
         sum+=second;    
      if( first >  4000000  || second > 4000000)
        break;
   }
   std::cout<<sum<<std::endl;
}
