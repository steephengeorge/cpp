#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<set>
 
int  parseRecord(std::string &record, std::vector<int>& rec)
{
    //std::cout<< "parseRecord: record:"<< record<<std::endl;
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
/*template<typename T1, typename T2>
struct comp{
    bool operator()(std::pair<T1,T2> x, std::pair<T1,T2> y)
    {
          if (( x.first == y.second) && (x.second == y.first) )
           return false ;
          else if ((x.second == y.second) && (x.first == y.first))
            return false;
          else
             return true;
 
    }
};*/
void createPairs(std::vector<int>& input_rec, int &second)
{
    //std::cout<<"create_pairs:second:"<<second<<std::endl;
    std::set<std::pair<int,int>, comp<int,int>> myPairs;
    for( auto & x: input_rec)
    {
        for( auto & y: input_rec)
       {
            if(x+y == second)
            {
 
                myPairs.emplace(std::pair<int,int>(x,y));
 
            }
        }
    }
    //std::cout<<"size:"<<myPairs.size()<<std::endl;
 
    for(std::set<std::pair<int,int> >::iterator it=myPairs.begin(); it != myPairs.end(); )
    {
        std::cout<<it->first<<","<<it->second;
        ++it;
        if(it != myPairs.end())
           std::cout<<";";
    }
    if(myPairs.size()==0)
      std::cout<<"NULL";
 
    std::cout<<std::endl;
}
void readInputFile(std::string filename)
{
    //std::cout<<"filename:"<<filename<<std::endl;
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
        //std::cout<<"record:"<<record<<std::endl;
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
