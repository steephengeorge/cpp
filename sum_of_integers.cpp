#include<iostream>
#include<fstream>


void readInputFile(std::string filename)
{      
    std::ifstream infile;
    infile.open(filename);
    std::string record;
    long long number=0;
    long long sum=0;
    while(true )
    {
        std::getline(infile,record);
        if(infile.eof())
                break;
        parse
        number =std::atoi(record.c_str());
        sum+=number;
    }
    std::cout<<sum<<std::endl;
}
int main(int argc, char* argv[])
{
   if(argc < 2)
   {
        std::cout<<"usage: sum_of_integers numbers.txt"<<std::endl;
        exit(0);
   }
 
   std::ios_base::sync_with_stdio(false);
   readInputFile(argv[1]);    
        
   return 0;
}
