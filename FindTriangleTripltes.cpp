#include <vector>
#include <iostream>

struct Triplet
{
    const int first;
    const int second;
    const int third;
};

bool isTriplet(int first, int second, int third)
{
    return   ( ( second + third  ) > first  )&&
             ( ( first + third   ) > second )&&
             ( ( first + second  ) > third  );
}

std::vector<Triplet> findTriangleTriplets( const std::vector<int>& vec_input )
{
    std::vector<Triplet> triplets;
    const size_t size = vec_input.size();

    for( unsigned int i=0; i < size; ++i )
    {
        for( unsigned int j = i; j < size; ++j )
        {
            for( unsigned int k = j; k < size; ++k)
            {
                const int first  ( vec_input.at( i ) );
                const int second ( vec_input.at( j ) );
                const int third  ( vec_input.at( k ) );

                if(isTriplet(first,second, third) )
                {
                    triplets.emplace_back( Triplet{ first, second, third } );
                }
            }
        }
    }
    return triplets;
}

int main()
{
    const std::vector<int> vec_input {2, 4, 5};

    std::vector<Triplet> triplets = findTriangleTriplets( vec_input );
    for ( auto &x : triplets )
    {
        std::cout<<x.first<<" "<<x.second<<" "<<x.third<<"\n";
    }
    return 0;
}
