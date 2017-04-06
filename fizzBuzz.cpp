/*
Players generally sit in a circle. The first player says the number “1”, and each
player says next number in turn. However, any number divisible by X (for example, three)
 is replaced by the word fizz, and any divisible by Y (for example, five) by the word
 buzz. Numbers divisible by both become fizz buzz. A player who hesitates, or makes a
 mistake is eliminated from the game.

Write a program that prints out the final series of numbers where those divisible by X, Y
and both are replaced by “F” for fizz, “B” for buzz and “FB” for fizz buzz.

INPUT SAMPLE:

Your program should accept a file as its first argument. The file contains multiple
separated lines; each line contains 3 numbers that are space delimited. The first number
 is the first divider (X), the second number is the second divider (Y), and the third
 number is how far you should count (N). You may assume that the input file is formatted
 correctly and the numbers are valid positive integers.

For example:



1
2
3 5 10
2 7 15
OUTPUT SAMPLE:

Print out the series 1 through N replacing numbers divisible by X with “F”, numbers
divisible by Y with “B” and numbers divisible by both with “FB”. Since the input file
contains multiple sets of values, your output should print out one line per set. Ensure
that there are no trailing empty spaces in each line you print.



1
2
1 2 F 4 B F 7 8 F B
1 F 3 F 5 F B F 9 F 11 F 13 FB 15
CONSTRAINTS:

The number of test cases ≤ 20
"X" is in range [1, 20]
"Y" is in range [1, 20]
"N" is in range [21, 100]

*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

struct input_rec{
    int first;
    int second;
    int last;
};

void parseRecord( std::string &record, input_rec& rec )
{
    int first  = 0;
    int second = 0;
    int last   = 0;
    bool good  = 0;

    size_t start = 0;
    size_t end =  record.find_first_of(" ");
    first = std::atoi(record.substr(start,end-start).c_str());
    if( ( 1 <= first ) && ( first <= 20 ) )
    {
        good = 1;
    }
    else
    {
        return;
    }

    start = end + 1;
    end = record.find_first_of( " ", start );
    second = std::atoi( record.substr( start, end-start ).c_str() );
    if( good && ( ( 1 <= second ) && ( second <= 20 ) ) )
    {
         good=1;
    }
    else
    {
        return;
    }
    start = end + 1;
    last = std::atoi( record.substr( start, std::string::npos ).c_str() );
    if( good && ( (21 <= last ) && ( second <= 200 ) ) )
    {
        good=1;
    }
    else
    {
        return;
    }
    if(good)
    {
        rec.first=first;
        rec.second=second;
        rec.last=last;
    }
}
void readInputFile( std::string fileName, std::vector< input_rec > & rec )
{
    std::ifstream infile( fileName );

    std::string record;
    input_rec temp;
    while( std::getline( infile, record ) )
    {

        parseRecord( record, temp );
        rec.emplace_back( temp );
    }
}
void checkfuzzbuzz( input_rec& rec )
{
    int x     = 1;
    int flag1 = 0;
    int flag2 = 0;

    while( x < rec.last )
    {
        if( ( x % rec.first ) == 0)
        {
            flag1 = 1;
        }
        if ( ( x % rec.second ) == 0 )
        {
            flag2 = 1;
        }

        if( ( flag1 + flag2 ) == 2 )
        {
            std::cout << "FB" << " ";
        }
        else if( flag1 == 1)
        {
            std::cout << "F" << " ";
        }
        else if( flag2 == 1 )
        {
            std::cout << "B" << " ";
        }
        else
        {
            std::cout << x << " ";
        }
        flag1 = 0;
        flag2 = 0;
        ++x;
    }
    if( x == rec.last )
    {
        if( ( x % rec.first ) == 0 )
        {
            flag1 = 1;
        }
        if ( ( x % rec.second ) == 0 )
        {
            flag2 = 1;
        }

        if( ( flag1 + flag2 ) == 2 )
        {
            std::cout << "FB";
        }
        else if( flag1 == 1)
        {
            std::cout << "F";
        }
        else if( flag2 == 1 )
        {
            std::cout << "B";
        }
        else
        {
            std::cout << x << " ";
        }
        flag1 = 0;
        flag2 = 0;
        ++x;
    }
    std::cout << "\n";
}
int main( int argc, char* argv[] )
{
    auto start = std::chrono::steady_clock::now();
    if( argc < 2 )
    {
        std::cout << "usage: fuuzbuzz fuuzbuzz.txt" << "\n";
        exit( 0 );
    }

    std::ios_base::sync_with_stdio( false );
    std::vector< input_rec > input;
    readInputFile( argv[ 1 ], input );
    for( auto &x : input)
    {
       checkfuzzbuzz(x);
    }
    auto end      = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout<< duration.count() << "\n";
    return 0;
}
