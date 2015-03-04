//Find file size
#include <iostream>
#include<stdio.h>
 
 
int main(int argc, char* argv[])
{    
    if(argc < 1)
    {
        std::cout<<"usage is filesize filename"<<std::endl;
        exit(0);
    }
    std::ios_base::sync_with_stdio(false);
    FILE* file= std::fopen(argv[1],"rb");
    if(!file)
    {
         std::cout<<"Failed to open file:"<<argv[1]<<std::endl;
    }
    fseek(file,0,SEEK_END);
    long size= ftell(file);
    fclose(file);
 
    std::cout<<size<<std::endl;
 
    return 0;
}
