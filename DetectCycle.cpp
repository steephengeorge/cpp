/*

Given a sequence, write a program to detect cycles within it.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename containing a sequence of numbers (space delimited). The file can have multiple such lines. E.g



1
2
3
2 0 6 3 1 6 3 1 6 3 1
3 4 8 0 11 9 7 2 5 6 10 1 49 49 49 49
1 2 3 1 2 3 1 2 3
OUTPUT SAMPLE:

Print to stdout the first cycle you find in each sequence. Ensure that there are no trailing empty spaces on each line you print. E.g.



1
2
3
6 3 1
49
1 2 3
The cycle detection problem is explained more widely on wiki
Constrains:
The elements of the sequence are integers in range [0, 99]
The length of the sequence is in range [0, 50]
*/

#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <set>
#include <fstream>
#include <sstream>

template<typename T>
class cyclicKeeper
{
    public:
        void push( T val)
        {
            cycles.push_back(val);
            cycleSet.emplace(val);
        }
        void clear()
        {
            for ( auto & x : cycles)
            {
                --counter[x];
            }
            cycles.clear();
            cycleSet.clear();
        }
        void incrementCounter(T val)
        {
            ++counter[val];
        }
        T counterValue(T val)
        {
            return counter[val];
        }
        void print()
        {
           std::vector<int> order( cycleSet.size());
           for( auto & x : cycleSet)
           {
                auto pos= std::find(std::begin(cycles), std::end(cycles),x);
                order[pos- std::begin(cycles)]=x;
           }
           for( auto &x : order)
           {
                std::cout<< x << " ";
           }
           std::cout<<"\n";
        }

    private:
        std::unordered_map<T,T> counter;
        std::vector<T> cycles;
        std::set<T> cycleSet;
};

void  processInputRecord(std::vector<int>& vec)
{
    cyclicKeeper<int> ck;
    for( auto & x : vec )
    {
       ck.incrementCounter(x);
    }

    int prev = 0;
    for( auto & x : vec )
    {
        if( ck.counterValue(x) > 1 )
        {
            if ( prev == 0)
            {
                prev = ck.counterValue(x);
                ck.push(x);
            }
            else if( prev ==  ck.counterValue(x) )
            {
                ck.push(x);
            }
            else
            {
                ck.clear();
                prev= ck.counterValue(x);
                ck.push(x);
            }
        }
        else
        {
            ck.clear();
            prev = 0;
        }
    }
    ck.print();
}

void readInputFile( std::string fileName )
{
    std::ifstream infile( fileName );
    std::vector<int> vec;
    std::string record;

    while( std::getline( infile, record ) )
    {
        std::istringstream iss(record);
        int temp = 0;
        while( iss >> temp )
        {
           vec.push_back(temp);
        }
        processInputRecord(vec);
        vec.clear();
    }
    infile.close();
}

int main( int argc, char* argv[] )
{
    if( argc < 2 )
    {
        std::cout << "Error: input file is missing " << "\n";
        exit( 0 );
    }

    std::ios_base::sync_with_stdio( false );
    readInputFile( argv[ 1 ]);

    return 0;
}
