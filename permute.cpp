#include <iostream>
#include<fstream>
#include<algorithm>
 
void readInputFile(std::string filename)
 
{
        //std::cout<<"readInputFile: filename:"<< filename<<std::endl;
        std::ifstream infile;
        infile.open(filename);
        std::string record;
        while(true )
        {
            std::getline(infile,record);
            // std::cout<<"readInputFile: record:"<< record<<std::endl;
            if(infile.eof())
                break;
            std::sort(record.begin(), record.end());
            bool flag=0;
            do{
                   if(flag)
                        std::cout<<",";
                   flag=1;
                   std::cout <<record;
            } while(std::next_permutation(record.begin(), record.end()));
            std::cout<<"\n";
 
        }
}
 
int main(int argc, char* argv[])
{
    if(argc < 1)
    {
        std::cout<<"usage is filesize filename"<<std::endl;
        exit(0);
    }
    std::ios_base::sync_with_stdio(false);
    readInputFile(argv[1]);
    //readInputFile();
 
    return 0;
}
