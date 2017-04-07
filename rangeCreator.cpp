/^
Given an array of ints, return a string identifying the range of numbers.

Example:

Input arr - [0 1 2 7 21 22 1098 1099]
Output - "0-2,7,21-22,1098-1099"
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::string  range_creator(std::vector<int> & vec)
{
    std::sort(std::begin(vec),std::end(vec));

    int first=vec.at(0);
    int prev=first-1;

    std::stringbuf buffer;
    std::ostream os (&buffer);

    for(auto &x : vec)
    {
       if(++prev == x)
           continue;
        else
        {

           if(first != --prev)
           {
               os << first<<"-"<<prev<<",";
               prev=x;
               first=x;
           }
           else
           {
               os<<first<<",";
               prev=x;
               first=x;
           }


        }

    }
    if(first != prev)
    {
        os<<first<<"-"<<prev;
    }
    else
    {
       os<<first;
    }
    return buffer.str();
}

int main()
{
    std::vector<int> vec={0,1,2,7,8,9,10,21,22,23,24,25,27,1098,1099,1100,2000};
    std::cout<<range_creator(vec);

    return 0;
}