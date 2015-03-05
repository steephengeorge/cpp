#include<iostream>
#include<fstream>
#include<vector>
#include<string>
 
int  parseRecord(std::string &record, std::vector<int>& rec)
{
  
    std::string first_part;
 
    size_t start = 0;
    size_t end =  record.find_first_of(";");
    first_part= record.substr(start,end-start);
 
    start=end+1;
    int second=std::atoi(record.substr(start,std::string::npos).c_str());
    //std::cout<<"second:"<<second<<std::endl;
 
    start=0;
    end= first_part.find_first_of(",");
 
    int val= std::atoi(first_part.substr(start, end-start).c_str());
    //std::cout<<"val:"<<val<<std::endl;
    rec.emplace_back(val);
 
    while(std::string::npos!=end )
    {
        start=end+1;
        end=first_part.find_first_of(",",start);
        val=std::atoi(first_part.substr(start, end-start).c_str());
        //std::cout<<"val:"<<val<<std::endl;
        rec.emplace_back(val);
    }
    return second;
}

void createPairs(std::vector<int>& input_rec, int &second)
{
    bool flag=0;
 
    for( auto & x: input_rec)
    {
        for( auto & y: input_rec)
        {
            if(x+y == second)
            {
                if(x<y)
                {
                    if(flag)
                         std::cout<<";";
 
                    std::cout<<x<<","<<y;
                    flag=1;
                }
 
            }
        }
    }
    if(!flag)
      std::cout<<"NULL";
 
    std::cout<<std::endl;
}
void readInputFile(std::string filename)
{
    std::ifstream infile;
    infile.open(filename);
 
    if(!infile)
    {
        std::cout<<"failed to open the file"<<std::endl;
    }
 
    std::string record;
    std::vector<int> input_rec;
    int second=0;
    while(true )
    {
        std::getline(infile,record);
        if(infile.eof())
              break;
        second=parseRecord(record, input_rec);
        createPairs(input_rec, second);
    }
}
int main(int argc, char* argv[])
{
   if(argc < 2)
   {
        std::cout<<"usage: create_pairs numbers.txt"<<std::endl;
       exit(0);
   }
   std::ios_base::sync_with_stdio(false);
   readInputFile(argv[1]);
   return 0;
}
