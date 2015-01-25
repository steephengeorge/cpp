
#include <iostream>
#include<iomanip>
 
int main()
{
    int withdraw;
    double balance;
    
    std::cin>> withdraw;
    std::cin>> balance;
    std::cout<<std::fixed;
    std::cout<<std::setprecision(2);
   
    if((withdraw%5 !=0) || ( withdraw+0.5 > balance)|| withdraw ==0)    
        std::cout<<balance<<'\n';
    else if(  balance > withdraw )
        std::cout<<std::showpoint<<(balance - withdraw-0.5)<<'\n';
        
} 
