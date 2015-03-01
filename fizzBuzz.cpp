#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<chrono>

struct input_rec{
    int first;
    int second;
    int last;
};
 
void parseRecord(std::string &record, input_rec& rec)
{
    int first=0;
    int second=0;
    int last=0;
    bool good=0;
   
    size_t start = 0;
                size_t end =  record.find_first_of(" ");
                first=std::atoi(record.substr(start,end-start).c_str());
    if((1<=first) && (first <=20))
        good=1;
    else
        return;
  
                start=end+1;
                end=record.find_first_of(" ",start);
    second=std::atoi(record.substr(start,end-start).c_str());
                if(good && ((1<=second) && (second <=20)))
         good=1;
    else
        return;
   
                start=end+1;
                last =std::atoi(record.substr(start,std::string::npos).c_str());
    if(good && ((21 <=last)&& (second <=200)))
         good=1;
    else
         return;
    if(good)
    {
        rec.first=first;
        rec.second=second;
        rec.last=last;
    }
}
void readInputFile(std::string filename,std::vector<input_rec> & rec )
{
               
        //std::cout<<"readInputFile: filename:"<< filename<<std::endl;
        std::ifstream infile;
        infile.open(filename);
                std::string record;
                input_rec temp;
                while(true )
                {
                                std::getline(infile,record);
               // std::cout<<"readInputFile: record:"<< record<<std::endl;
                if(infile.eof())
                      break;
                                parseRecord(record,temp);
                                rec.emplace_back(temp);
                }
}
void checkfuzzbuzz(input_rec& rec)
{ 
    int x=1;
    int flag1 =0;
    int flag2 =0;
    while(x < rec.last)
    {
        if((x%rec.first)==0)
        {
            flag1=1;
        }
        if ((x%rec.second)==0)
        {
            flag2=1;
        }
       
        if((flag1+flag2)==2)
        {
            std::cout<<"FB"<<" ";           
        }
        else if(flag1 ==1)
        {
            std::cout<<"F"<<" ";
        }   
        else if(flag2==1)
        {
            std::cout<<"B"<<" ";
        }
        else
        {
            std::cout<<x<<" ";
        }
        flag1=0;
        flag2=0;
        ++x;
    }
    if(x ==rec.last)
    {
        if((x%rec.first)==0)
        {
            flag1=1;
        }
        if ((x%rec.second)==0)
        {
            flag2=1;
        }
       
        if((flag1+flag2)==2)
        {
            std::cout<<"FB";           
        }
        else if(flag1 ==1)
        {
            std::cout<<"F";
        }   
        else if(flag2==1)
        {
            std::cout<<"B";
        }
        else
        {
            std::cout<<x<<" ";
        }
        flag1=0;
        flag2=0;
        ++x;
    }
    std::cout<<std::endl;
}
int main(int argc, char* argv[])
{
    auto start = std::chrono::steady_clock::now();
    if(argc < 2)
    {
        std::cout<<"usage: fuuzbuzz fuuzbuzz.txt"<<std::endl;
        exit(0);
    }
 
    std::ios_base::sync_with_stdio(false);
    std::vector<input_rec> input;
    readInputFile(argv[1], input);    
    for( auto &x : input)
    {
       checkfuzzbuzz(x);
    }
   auto end = std::chrono::steady_clock::now();
   auto duration= std::chrono::duration_cast<std::chrono::microseconds>(end-start);
   std::cout<< duration.count()<<std::endl;
    return 0;
}
 
