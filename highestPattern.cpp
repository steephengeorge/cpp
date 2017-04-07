/*
You are given 3 strings: text, pre_text and post_text. Let L be a substring of text. For each substring L of text, we define pattern_score as follows:

pre_text_pattern_score = highest n, such that first n characters of L are equal to the last n characters of pre_text and occur in the same exact order.
post_text_pattern_score = highest n such that last n characters of L are equal to the first n characters of post_text and occur in the same exact order.
pattern_score = pre_text_pattern_score + post_text_pattern_score. For example, if L = "nothing", pre_text = "bruno", and post_text = "ingenious", then
pre_text_pattern_score of L is 2 because the substring "no" is matched, and
post_text_pattern_score is 3 because the substring "ing" is matched.
pattern_score is 5 = 2 + 3 Your program should find a non-empty substring of text that maximizes pattern_score.
If there is a tie, return the substring with the maximal pre_text_pattern_score.
If multiple answers still have a tied score, return the answer that comes first lexicographically. Complete the definition of function  string calculateScore(string text, string prefix,string suffix)
Constraints:

text, pre_text, and post_text contain only lowercase letters ('a' - 'z')
1 <= |text| <= 50
1 <= |pre-text| <= 50
1 <= |post-text| <= 50 (where |S| denotes the number of characters in string S)
Sample case #1 text: "nothing" prefix: "bruno" suffix: "ingenious" Returns: "noing"

Sample case #2 text: "ab" prefix: "b" suffix: "a" Returns: "a"
*/

#include <iostream>
#include <string>
#include <vector>
#include <regex>

void  tokenize(std::string & text, std::vector<std::string>& text_prefix_tokens, std::vector<std::string>& text_suffix_tokens )
{
     std::string text_copy(text);
     int length =  text_copy.length();

     int i = 1;
     while( i <= length )
     {
          text_prefix_tokens.push_back(text_copy.substr(0, i));
          ++i;
     }

     while( length-- )
     {
          text_suffix_tokens.push_back(text_copy.substr(length));
     }
}



std::string findHighestPattern(std::string & pre_text, std::string & post_text, std::string & text)
{
     std::vector<std::string> text_prefix_tokens;
     std::vector<std::string> text_suffix_tokens;
     tokenize(text, text_prefix_tokens, text_suffix_tokens);

     std::smatch matches;
     int post_text_score = 0;

     std::string post_result;
     for( auto &x : text_suffix_tokens)
     {
        std::regex pattern (x+"(.*)");
        std::regex_match(post_text,matches,pattern);

        if(matches.size() > 0)
        {
            int post_length = x.length();
            if(post_length > post_text_score)
            {
                post_text_score = post_length;
                post_result = x;
            }
        }
    }
    int pre_text_score = 0;

    std::string pre_result;
    for( auto &x : text_prefix_tokens)
    {
        std::regex pattern ("(.*)"+x);
        std::regex_match(pre_text, matches, pattern);

        if(matches.size() > 0)
        {
            int pre_length = x.length();
            if(pre_length > pre_text_score)
            {
                pre_text_score = x.length();
                pre_result = x;
            }
        }
    }
    std::string result = pre_result + post_result;
    if(result.length() == 0)
    {
        text_suffix_tokens.insert(std::end(text_suffix_tokens), std::begin(text_prefix_tokens), std::end(text_prefix_tokens));
        std::sort(std::begin(text_suffix_tokens),std::end(text_suffix_tokens));

        result = text_suffix_tokens.at(0);
    }
    return result;
}


int main()
{
     std::string pre_text ("bruno");
     std::string text("nothing");
     std::string post_text("ingenious");

     //std::string pre_text ("b");
     //std::string text("ab");
     //std::string post_text("a");

     std::cout<< findHighestPattern(pre_text,post_text,text) <<"\n";
}