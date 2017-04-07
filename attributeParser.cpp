/*We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ... >

The closing tags follow the format:

< /tag-name >

For example:

<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
The attributes are referenced as:

tag1~value
tag1.tag2~name
You are given the source code in HRML format consisting of  lines. You have to answer  queries. Each query asks you to print the value of the attribute specified. Print "Not Found!" if there isn't any such attribute.

Input Format

The first line consists of two space separated integers,  and .  specifies the number of lines in the HRML source program.  specifies the number of queries.

The following  lines consist of either an opening tag with zero or more attributes or a closing tag.

 queries follow. Each query consists of string that references an attribute in the source program.

Constraints



Each line in the source program contains, at max,  characters.
Every reference to the attributes in the  queries contains at max  characters.
All tag names are unique.

Output Format

Print the value of the attribute for each query. Print "Not Found!" without quotes if there is no such attribute in the source program.

Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
Sample Output

Name1
Not Found!
HelloWorld
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <iterator>



int main() {
    std::string first;
    std::getline(std::cin, first);
    std::istringstream iss(first);
    std::vector<int> tokens1;
    std::copy(std::istream_iterator<int> (iss),
                 std::istream_iterator<int>(),
                 std::back_inserter(tokens1));

    int n = tokens1[0], q=tokens1[1];
    std::string source;
    std::map<std::string, std::string> tagValue;
    std::string tagKey;

    while( n > 0){
        std::string input;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::copy(std::istream_iterator<std::string> (iss),
                   std::istream_iterator<std::string>(),
                   std::back_inserter(tokens));

        if( tokens.size() >=1)
        {
            std::string tag = tokens[0];
            if( tag[0] == '<' && tag[1] != '/')
            {

                if( tag[tag.size()-1]== '>')
                     tagKey.empty() ? tagKey = tag.substr(1,tag.size()-2):
                                      tagKey = tagKey+"."+tag.substr(1, tag.size()-2);
                else
                     tagKey.empty() ? tagKey = tag.substr(1):
                                      tagKey = tagKey+"."+tag.substr(1);
            }
            if( tag[0] == '<' && tag[1] == '/')
            {
                auto found = tagKey.find_last_of(".");
                if( found != std::string::npos)
                   tagKey.erase(tagKey.begin()+found, tagKey.end());
                else
                   tagKey="";
            }
        }
        if(tokens.size() > 1 )
        {
            int i = 1;
            while( i+2 < tokens.size() )
            {
                std::string name = tokens[i];
                std::string value = tokens[i+2];
                if( value[value.size()-1]== '>')
                    tagValue[tagKey+"~"+name] = value.substr(1, value.length()-3);
                else
                    tagValue[tagKey+"~"+name] = value.substr(1, value.length()-2);
                i+=3;
            }
        }
        --n;

    }

    std::string input1;
    while(  std::getline(std::cin, input1)) {

        if( q < 0)
            break;
         std::istringstream iss(input1);
         std::vector<std::string> tokens;
         std::copy(std::istream_iterator<std::string> (iss),
                   std::istream_iterator<std::string>(),
                   std::back_inserter(tokens));

         (tagValue.find(tokens[0]) != tagValue.end()) ?
                                      std::cout<<tagValue[tokens[0]]<<"\n" :
                                      std::cout<<"Not Found!\n";
       --q;
    }
}
