#include <iostream>
#include <string>
#include <vector>
#include<algorithm>


using namespace std;    

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
    if( newInterval.start > newInterval.end)
      std::swap(newInterval.start, newInterval.end);
   /* for( auto& ele: intervals)
    {
        std::cout<<"("<<ele.start<<","<<ele.end<<")";
    }
    std::cout<<"\n";*/
    
    std::vector<Interval> result;
    if(intervals.size() == 0)
    {
        result.emplace_back(newInterval);
        return result;
    }
    else if( newInterval.end <  intervals[0].start)
    {
         result.emplace_back(newInterval);
         std::copy(std::begin(intervals), std::end(intervals),  std::back_inserter(result));
         return result;
    }
    else if( newInterval.start > intervals[intervals.size()-1].end)
    {
       std::copy(std::begin(intervals), std::end(intervals), std::back_inserter(result));
       result.emplace_back(newInterval);
       return result;
    }
    else if( newInterval.start <=  intervals[0].start &&  newInterval.end >= intervals[intervals.size()-1].end )
    {
        result.emplace_back(newInterval);
        return result;
    }
    else
    {
        bool flag = false;
        int mini=0;
        int maxi=0;
        for ( size_t i =0; i< intervals.size(); ++i)
        {
            //std::cout<<intervals[i].start <<"|"<<intervals[i].end<<"\n";
            if(std::max(intervals[i].start, newInterval.start) < std::min(intervals[i].end, newInterval.end))
            {
                if( flag== false)
                {
                   mini= std::min(intervals[i].start, newInterval.start);
                   flag = true;
                }
                maxi= std::max( intervals[i].end, newInterval.end);
                continue;
            }
            if( flag)
            {
                result.emplace_back(Interval(mini,maxi));
                flag = false;  
                
            }
            if(   i+1 <= intervals.size()-1)
            {
                if(intervals[i].end <  newInterval.start &&  intervals[i+1].start > newInterval.end)
                {
                    result.emplace_back(intervals[i]); 
                    result.emplace_back(newInterval);  
                    continue;
                }
            }
            result.emplace_back(intervals[i]);        
       }
        if( flag)
        {
                result.emplace_back(Interval(mini,maxi));
        }
    }
    return result;
}
int main()
{
    std::vector<Interval> X= {{Interval(31935139, 38366404)}, {Interval(54099301, 76986474)}, {Interval(87248431, 94675146)}};
    Interval s(43262807, 68844111);
    std::vector<Interval> re=insert(X,s);
    for( auto& ele: re)
    {
        std::cout<<"("<<ele.start<<","<<ele.end<<")";
    }
}
