1. (a,b) and (b,a) are allowed

#include<map>
#include<iostream>

int main()
{
std::multimap<int,int> A;
int num[4]={2,4,5,6};
for(int i=0;i<4;++i)
{
   for(int j=0;j<4;++j)
   {
      if(i!=j)
      {
         A.insert(std::pair<int,int>(num[i],num[j]));
      }
   }
}

for( auto &k : A)
  std::cout<<k.first<<","<<k.second<<"\n";

return 0;
}

2. Either (a,b) or (b,a) is allowed
#include<map>
#include<iostream>

int main()
{
std::multimap<int,int> A;
int num[4]={2,4,5,6};
for(int i=0;i<4;++i)
{
   for(int j=0;j<4;++j)
   {
      if(i!=j)
      {
         A.insert(std::pair<int,int>(num[i],num[j]));
      }
   }
}

for( auto &k : A)
  std::cout<<k.first<<","<<k.second<<"\n";

return 0;
}
