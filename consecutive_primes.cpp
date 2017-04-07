/*
Write a program which determines the Mth to the last element in a list.

Input sample:

The first argument is a path to a file. The file contains the series of space delimited characters followed by an integer. The integer represents an index in the list (1-based), one per line.

For example:
a b c d 4

e f g h 2

Output sample:

Print to stdout the Mth element from the end of the list, one per line. If the index is larger than the number of elements in the list, ignore that input.

For example:
a

g
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

    void processRecords( const std::string& record )
    {
         auto splitLoc= record.rfind(" ");

         std::string::size_type index = std::stoi( record.substr( splitLoc ) );
         std::string str( std::begin( record ), std::begin( record ) + splitLoc );
         str.erase( std::remove_if( str.begin(), str.end(),
                                      []( const char& val ) {
                                          return std::isspace( val );
                                        }), str.end() );

         if( str.size() >= index )
         {
              std::cout << str[ str.size() - index ] << "\n";
         }
    }

    void readInputFile( const std::string fileName )
    {
         std::ifstream infile( fileName );
         std::string record;

         while( std::getline( infile, record ) )
         {
             processRecords( record );
         }

         infile.close();
    }

    int main( int argc, char* argv[] )
    {
        if( argc < 2 )
        {
            std::cout << "Usage: " << argv[0] << " input_file_name\n";
            exit( 0 );
        }

        std::ios_base::sync_with_stdio( false );
        readInputFile( argv[ 1 ] );
    }
