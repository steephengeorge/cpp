/*
Write a program which prints all the permutations of a string in alphabetical order.
We consider that digits < upper case letters < lower case letters. The sorting should
 be performed in ascending order.

INPUT SAMPLE:

Your program should accept a file as its first argument. The file contains input strings,
one per line.

For example:



1
2
3
hat
abc
Zu6
OUTPUT SAMPLE:

Print to stdout the permutations of the string separated by comma, in alphabetical order.

For example:



1
2
3
aht,ath,hat,hta,tah,tha
abc,acb,bac,bca,cab,cba
6Zu,6uZ,Z6u,Zu6,u6Z,uZ6

*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

void create_permute(  std::string& record )
{
    std::sort( record.begin(), record.end() );
    std::cout<<record;

    while( std::next_permutation( record.begin(), record.end() ) )
    {
        std::cout<<","<<record;
    }
    std::cout << "\n";
}
void readInputFile( std::string filename )
{
    std::ifstream infile(filename);
    std::string record;
    while( std::getline( infile,record ) )
    {
       create_permute( record );
    }
    infile.close();
}

int main( int argc, char* argv[] )
{
    if( argc < 2 )
    {
        std::cout << "usage: filesize filename" << "\n";
        exit( 0 );
    }
    std::ios_base::sync_with_stdio( false );
    readInputFile( argv[ 1 ] );

    return 0;
}
