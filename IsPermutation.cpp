#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <list>

template < typename T1 >
std::unordered_map< int, int > count_frequency( T1 first, T1 last )
{
    std::unordered_map< int, int > temp_unordered_map;
    auto temp_unordered_map_end = std::end( temp_unordered_map );
    while( first != last )
    {
        auto it_temp_unordered_map = temp_unordered_map.find( *first );
        if( it_temp_unordered_map == temp_unordered_map_end )
        {
            temp_unordered_map.emplace( *first, 1 );
        }
        else
        {
            ++( it_temp_unordered_map->second );
        }
        ++first;
    }
    return temp_unordered_map;
}

template < typename T1, typename T2 >
bool is_permutation( const T1 first1, const T1 last1, const T2 first2, const T2 last2 )
{
    if( std::distance( first1, last1 ) != std::distance( first2, last2 ) )
    {
        return false;
    }
    std::unordered_map< int, int > first_map = count_frequency( first1, last1 );
    std::unordered_map< int, int > second_map = count_frequency( first2, last2 );

    std::pair<std::unordered_map< int, int >::iterator,std::unordered_map< int, int >::iterator > myPair=
        std::mismatch( std::begin( first_map ), std::end( first_map ), std::begin( second_map ),
        []( std::pair< const int, int >& seed1, std::pair< const int, int > & seed2)
        { return seed1.second == seed2.second; }
        );

    return  myPair.first == first_map.end() && myPair.second == second_map.end();
}

int main()
{
    const std::array< int, 5> array1 { { 1, 3, 2, 4, 5 } };
    const std::array<int,4> array2 { { 1, 2, 4, 3 } };

    if( ::is_permutation( std::begin( array1 ), std::end( array1 ), std::begin( array2 ), std::end( array2 ) ) )
    {
        std::cout<< " Elements are permutation of each other\n";
    }
    else
    {
        std::cout<< " Elements are not permutation of each other\n";
    }

    const std::vector< int > vec1 { { 1, 3, 2, 4 } };
    const std::vector< int > vec2 { { 1, 2, 4, 3 } };

    if( ::is_permutation( std::begin( vec1 ), std::end( vec1 ), std::begin( vec2 ), std::end( vec2 ) ) )
    {
        std::cout<< " Elements are permutation of each other\n";
    }
    else
    {
        std::cout<< " Elements are not permutation of each other\n";
    }

    const std::list< int > list1 { { 1, 3, 2, 4 } };
    const std::list< int > list2 { { 1, 2, 4, 3 } };

    if( ::is_permutation( std::begin( list1 ), std::end( list1 ), std::begin( list2 ), std::end( list2 ) ) )
    {
        std::cout<< " Elements are permutation of each other\n";
    }
    else
    {
        std::cout<< " Elements are not permutation of each other\n";
    }
    return 0;
}