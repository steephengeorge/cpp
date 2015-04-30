#include <iostream>
#include<fstream>
#include<algorithm>
#include<string>

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
