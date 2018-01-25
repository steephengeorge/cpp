/*

Alice has an even number of N beads, and each bead has a number from 1 to N painted on it. She would like to make a necklace out of all the beads, with a special requirement: any two beads next to each other on the necklace must sum to a prime number. Alice needs your help to calculate how many ways it is possible to do so.

For example:

N = 4

There are two possible ways to build the necklace. Note that the last bead connects to the first bead.

1 2 3 4
1 4 3 2
Note: The necklace should be unique.
For example: 1 2 3 4 is the same as 2 3 4 1 and 3 4 1 2 and 4 1 2 3.



So the answer is 2.

INPUT SAMPLE:

The inputs consists of one even integer on a line. Each integer N is 2 <= N <= 18.

For example:



1
2
3
2
4
5
OUTPUT SAMPLE:

Print a line containing the number of ways to make a necklace according to the above rules. If not even number print 0.

For example:



1
2
3
1
2
0
CONSTRAINTS:

2 <= N <= 18
Number of test cases is 5.

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>


//if Yes return true;
//if No return false;
inline bool const find_in_vec( std::vector<int> vec, const int x )
{
    std::sort( vec.begin(), vec.end() );
    return std::binary_search( vec.begin(), vec.end(), x );
}

std::vector<std::vector<int>> insertOddNumber( std::vector<std::vector<int>> &vec,
                     const int num, const int pos )
{
    int prime_vec[ 10 ][ 8 ] ={ {},
                           { 3, 5, 9, 11, 15, 17, 0, 0 },        //2//
                           { 3, 7, 9, 13, 15, 0, 0, 0  },          //4//
                           { 5, 7, 11,13, 17, 0, 0, 0  },        //6//
                           { 3, 5, 9, 11, 15, 0, 0, 0  },         //8
                           { 3, 7, 9, 13, 0, 0, 0,  0  },            //10
                           { 5, 7, 11,17, 0, 0, 0,  0  },               //12
                           { 3, 5, 9, 15, 17, 0, 0, 0  },         //14
                           { 3, 7, 13,15, 0, 0, 0, 0  },          //16
                           { 5, 11,13, 0, 0, 0, 0, 0 } };            //18

    std::vector<std::vector<int>> eVecTemp;
    for(auto &x: vec)
    {
        int index = x.at( pos-1 ) * 0.5;
        int i = 0;
        while( index )
        {
            int candidate = prime_vec[ index ][ i++ ];

            if( ( candidate == 0 ) || ( candidate   > num ))
            {
                break;
            }

            if( !find_in_vec( x, candidate ) )
            {
                 eVecTemp.emplace_back( x );
                 eVecTemp.back().push_back( candidate );
            }
        }

    }
    return eVecTemp;
}

int updateLastdigit( std::vector<std::vector<int>>& vec, const int num )
{
    int prime[11]  = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for( auto &x: vec )
    {
        int sum= x.at( num-1 ) +1;

        if( !std::binary_search( prime, prime+11, sum ) )
        {
            x.clear();
        }

    }
    return std::count_if( vec.begin(), vec.end(), [](std::vector<int> & x){ return !( x.empty() );} );
}

std::vector<std::vector<int>> insertEvenNumber(std::vector<std::vector<int>>& vec,
                      const int num, const int pos)
{

    int prime_vec[10][8]={ {},
                           { 2, 4, 6, 10, 12, 16, 18, 0 },     //1//
                           { 2, 4, 8, 10, 14, 16, 0, 0  },        //3//
                           { 2, 6, 8, 12, 14, 18, 0, 0  },       //5//
                           { 4, 6, 10, 12, 16, 0, 0, 0  },         //7
                           { 2, 4, 8, 10,  14, 0, 0, 0  },          //9
                           { 2, 6, 8, 12,  18, 0, 0, 0 },          //11
                           { 4, 6, 10, 16, 18, 0, 0, 0 },         //13
                           { 2, 4, 8, 14,  16, 0, 0, 0 },          //15
                           { 2, 6, 12, 14,  0, 0, 0, 0 } };          //17

    std::vector<std::vector<int>> eVecTemp;
    for( auto &x: vec )
    {
        int index = ( x.at( pos-1 ) * 0.5 ) + 1;
        int i = 0;

        while( index )
        {
            int candidate = prime_vec[ index ][ i++ ];

            if( ( candidate == 0 ) || ( candidate  > num ) )
            {
                break;
            }

            if( !find_in_vec( x, candidate ) )
            {
                eVecTemp.emplace_back( x );
                eVecTemp.back().push_back( candidate );
            }
        }

    }
    return eVecTemp;
}

inline void insert_first( std::vector<std::vector<int>>& vec,
                          const int num )
{
    std::vector<int> temp;
    temp.emplace_back( 1 );
    vec.emplace_back( temp );
}

int create_consecutive_primes( const int num )
{
    std::vector< std::vector<int>> vec;
    if( num >= 2 )
    {
        insert_first( vec, num );
        vec = insertEvenNumber( vec, num, 1 );
        if( num == 2 )
        {
              return updateLastdigit( vec, num );
        }
    }
    if( num >= 4 )
    {
         vec = insertOddNumber( vec, num, 2 );
         vec = insertEvenNumber( vec, num, 3 );
         if( num == 4 )
         {
              return updateLastdigit( vec, num );
         }
    }
    if( num >= 6 )
    {
         vec = insertOddNumber( vec, num, 4 );
         vec = insertEvenNumber( vec, num, 5 );
         if( num == 6)
         {
              return updateLastdigit( vec, num );
         }
     }
     if( num >= 8 )
     {
         vec = insertOddNumber( vec, num, 6 );
         vec=insertEvenNumber( vec, num, 7 );
         if( num == 8)
         {
              return updateLastdigit( vec, num );
         }
     }
     if( num >= 10 )
     {
         vec=insertOddNumber( vec, num, 8 );
         vec=insertEvenNumber( vec, num, 9 );
         if( num == 10 )
         {
              return updateLastdigit( vec, num );
         }
     }
     int count = 0;
     for( auto & x: vec)
     {
          std::vector< std::vector<int>> vec1;
          vec1.emplace_back( x );
          for( int i = 10; i < num; ++i )
          {
              vec1=insertOddNumber( vec1, num, i );
              if( !vec1.empty() )
                  vec1 = insertEvenNumber( vec1, num, ++i );
          }

          count += updateLastdigit( vec1, num );
      }
      return count;
}

void readInputFile(const std::string filename )
{
    std::ifstream infile( filename );
    std::string record;

    while( std::getline( infile, record ) )
    {

        const int num = atoi( record.c_str() );
        if( num < 2 || num > 18 || (num %2 != 0 ))
        {
            std::cout<< 0 <<"\n";
            continue;
        }
        std::cout << create_consecutive_primes( num ) << "\n";
    }
    infile.close();
}

int main( int argc, char* argv[] )
{
    auto start = std::chrono::steady_clock::now();
    if( argc < 2 )
    {
        std::cout << "usage is filesize filename" << "\n";
        exit( 0 );
    }
    std::ios_base::sync_with_stdio( false );
    readInputFile( argv[ 1 ] );

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds> ( end - start );
    std::cout << duration.count() << "\n";
}

