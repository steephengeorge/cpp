#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <deque>

char findFirst(std::string& s)
{
    std::deque<char> chars;
    std::set<char> repeated;

    for(const auto& ele: s)
    {
        auto found = std::find(chars.begin(), chars.end(), ele);
        auto found2 = repeated.find(ele);
        if(found != chars.end())
        {
            chars.erase(found);
            repeated.insert(ele);
        }
        else if(found2 == repeated.end())
        {
            chars.push_back(ele);
        }

    }
    if( chars.size()> 0)
    {
        return chars.at(0);
    }
    else
    {
        return '*';
    }
}

int main()
{
    std::string s="aaabbccddeefgghjjkk";
    std::cout<<findFirst(s);

}
