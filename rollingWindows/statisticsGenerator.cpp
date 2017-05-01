#ifndef STATISTICSGENERATOR_H
#include "statisticsGenerator.h"
#endif

statisticsGenerator::statisticsGenerator(std::vector<int>& windowSizes)
{
    this->windowSizes.swap(windowSizes);
    
    for(size_t i = 0; i < this->windowSizes.size() ; ++i)
    {
         windows.push_back(std::deque<double>());
         bookKeeper.push_back(book());
    }
}

std::deque<double> statisticsGenerator::getWindow(const int index)
{
     return windows[index];
}
int statisticsGenerator::getCurrentWindowSize(const int index)
{
     return windows[index].size();
}
int statisticsGenerator::countOfWindows()
{
     return windowSizes.size();
}
void statisticsGenerator::insertIntoWindow(const int index, const double value)
{
     windows[index].push_back(value);
}
void statisticsGenerator::popFromWindow(const int index)
{
     windows[index].pop_front();
}
double statisticsGenerator::popValueFromWindow(const int index)
{
     return windows[index].front();
}
int statisticsGenerator::getWindowSize(const int index)
{
    return windowSizes[index];
}


std::vector<statistics>  statisticsGenerator::getNext(double newVal)
{
    size_t windowsCount = countOfWindows();
    size_t invalidCount = 0;
    std::vector<statistics> results(windowsCount,statistics());
    for( size_t i = 0; i < windowsCount; ++i)
    {
        insertIntoWindow(i,newVal);
        auto currentWindow = getWindow(i);
        if(!std::isnan(newVal))
        {
             if(bookKeeper[i].max < newVal)
                bookKeeper[i].max = newVal;  
              bookKeeper[i].sum += newVal;
        }
        auto found = find_if(currentWindow.begin(), currentWindow.end(), [](const auto& val) { return std::isnan(val);} );
        if(getCurrentWindowSize(i) < getWindowSize(i) ||
           found != currentWindow.end())
        {
            results[i].valid = false;
            ++invalidCount;
        }
        if((!results[i].valid) &&  (getCurrentWindowSize(i) == getWindowSize(i)) )  
        {
            double popValue =  popValueFromWindow(i);
            popFromWindow(i);  
            bookKeeper[i].sum -= popValue;
            if(popValue == bookKeeper[i].max)
                 bookKeeper[i].max =  *std::max_element(currentWindow.begin(), currentWindow.end());
        } 
    }
    if( invalidCount == windowsCount)
    {
         return results;
    }
    for( size_t i = 0; i < windowsCount; ++i)
    {
        if(results[i].valid)
        {
             auto currentWindow = getWindow(i);
             results[i].max = bookKeeper[i].max;
             results[i].mean = bookKeeper[i].sum/getWindowSize(i);
             double popValue =  popValueFromWindow(i);
             popFromWindow(i);
             bookKeeper[i].sum -= popValue;
             if(popValue == bookKeeper[i].max)
                 bookKeeper[i].max =  *std::max_element(currentWindow.begin(), currentWindow.end());
 
        }
    }
    return results;
}

