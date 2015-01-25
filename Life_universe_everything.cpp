//codechef 
//Life, the Universe, and Everything

#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> v;
    int x;
    while(std::cin>>x )
    {
        if(x == 42)
          break;
        v.push_back(x);
    }        
    for( auto &x:v)
       std::cout<<x<<'\n';
}
