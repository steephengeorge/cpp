/*
print matrix spirally*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<int> spiralOrder(const std::vector<std::vector<int> > &A) {
    std::vector<int> result;

    int T = 0;
    int B = A.size()-1;
    int L = 0;
    int R = A[0].size()-1;
    auto dir = 0;

    while ( T <= B && L <= R)
    {
        if(dir == 0)
        {
            for( auto i = L; i <= R; ++i)
            {
               result.emplace_back(A[T].at(i));
            }
            ++T;
            ++dir;
        }



        else if( dir == 1)
        {
            for( auto i = T ; i <= B; ++i )
            {
                result.emplace_back( A[i].at(R));
            }
            --R;
            ++dir;
        }

        else if(dir == 2)
        {
            for(auto  i = R;  i >= L ; --i )
            {

                result.emplace_back( A[B].at(i) );
            }
            --B;
            ++dir;
        }
        else if ( dir == 3)
        {
            std::cout<<"B:"<<B<<"\n";
            std::cout<<"T:"<<T<<"\n";
            std::cout<<"L:"<<L<<"\n";
            for( auto  i = B; i >= T ; --i)
            {
                std::cout << "i:"<<i<<"\n";
                std::cout<< A[i].at(L) << "\n";
               // result.emplace_back( A[i].at(L) );
            }
            ++L;
            ++dir;
        }
        dir= dir % 4;

    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> A = {{1, 2},  {3, 4}, {5, 6}};
    auto vec= spiralOrder(A);


    for (auto &x: vec)
      std::cout<<x<<",";

}
