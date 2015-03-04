#include <iostream>

int main()
{    
    std::ios_base::sync_with_stdio(false);
    int i=1;
    
     if(i <100)
     {
        do{
               if(i%2!=0)
               {
                  std::cout<<i<<std::endl;
               }
               ++i;
         }while(i<100);
     }
    return 0;
}
