#ifndef INPUTSTREAM_H
#include "inputStream.h"
#endif
#ifndef STATISTICSGENERATOR_H
#include "statisticsGenerator.h"
#endif

std::vector<std::vector<statistics>> generateStaticsforWindows(const std::string& filePath, std::vector<int>& windowSize )
{
    inputStream input(filePath); 
    std::vector<std::vector<statistics>> collectionOfStatistics;
    statisticsGenerator generator(windowSize);


    while(input.hasNext())
    {
        double value = input.getNext();
        auto stat = generator.getNext(value);
        collectionOfStatistics.push_back(stat);
    }
    return collectionOfStatistics;
}

int main(int argc, char* argv[])
{
   std::vector<int> windowSize;
   std::string filePath;
   if( argc < 3)
   {
       std::cout << "Usage : rollingWindows <filepath> <windowsize1> <windowsize2> <windowSize>......\n";
       return 0;
   }
   else
   {
        filePath = argv[1]; 
        for(int i = 2; i < argc; ++i)
        {
            windowSize.push_back(std::atoi(argv[i])); 
        }
   }
   std::vector<std::vector<statistics> > vec = generateStaticsforWindows(filePath, windowSize);
   for(size_t i = 0; i < vec.size(); ++i )
   {
       std::cout << "next lap results:\n";
       for(size_t j = 0; j < vec[i].size(); ++j )
       {
            if(vec[i][j].valid)
            {
                 std::cout << vec[i][j].valid << " " << vec[i][j].mean << " " <<vec[i][j].max << "\n";
            }
       }
   }
}

