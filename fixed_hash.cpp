//C++14 program:
//


  /*  Write a program which reads a file and prints to stdout the specified number of the longest lines that are sorted based on their length in descending order. Input sample:

    Your program should accept a path to a file as its first argument. The file contains multiple lines. The first line indicates the number of lines you should output, the other lines are of different length and are presented randomly. You may assume that the input file is formatted correctly and the number in the first line is a valid positive integer.

    For Example:

    2 
    Hello World
    CodeEval 
    Quick Fox
    A
    San Francisco

    Output sample:

    Print out the longest lines limited by specified number and sorted by their length in descending order.

    For example:

    San Francisco 
    Hello World

*/

#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<chrono>

class fixed_hash{
public:
        fixed_hash( std::size_t pSize )
        {
            size = pSize;
        }
        void push( std::string & record )
        {

            if( hash_table.size() < size )
            {
                hash_table.emplace( std::make_pair( record.size(), record ) );
            }
            else if( record.size() > hash_table.begin()->second.size() )
            {
                hash_table.erase( hash_table.begin() );
                hash_table.emplace( std::make_pair( record.size(), record ) );
            }
        }
        void print()
        {
            auto end = std::rend(hash_table);            
            for( auto it = std::rbegin( hash_table ); it != end ; ++it )            
            {
                std::cout << it->second << "\n";
            }
        }

 private:
        std::multimap<int,std::string> hash_table;
        std::size_t size;
};

void readInputFile( std::string fileName )
{
    std::ifstream infile( fileName );
    std::string record;
    int output_nbr = 0;
    infile >> output_nbr;
    fixed_hash output_string_list( output_nbr );
    while( std::getline( infile, record ) )
    {
        output_string_list.push( record );
    }

    output_string_list.print();
    infile.close();
}

int main( int argc, char* argv[] )
{
    auto start = std::chrono::steady_clock::now();
    if( argc < 2 )
    {
        std::cout << "Error: input file is missing " << "\n";
        exit( 0 );
    }

    std::ios_base::sync_with_stdio( false );
    readInputFile( argv[ 1 ]);

    auto end      = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout<< duration.count() << "\n";
    return 0;
}
