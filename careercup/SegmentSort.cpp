/*
You are given an alphanumeric string. Complete the function sortSegments that will
segment the string into substrings of consecutive letters or numbers and then sort the substrings.

For example, the string "AZQF013452BAB" will result in "AFQZ012345ABB". The input letters will
be uppercase and numbers will be between 0 and 9 inclusive.
*/

#include <iostream>
#include <string>
#include <algorithm>

void sortSegments(std::string& input)
{
    bool toggle1 = isalpha(input[0])? true: false;
    size_t k = 0;
    for(size_t i = 1; i <= input.size(); ++i)
    {
        bool toggle2 = isalpha(input[i])? true: false;
        if(toggle1 != toggle2)
        {
            std::sort(input.begin()+k, input.begin()+i);
            toggle1 = toggle2;
            k=i;
        }
    }
}

int main()
{
    std::string input("AZQKF013452BAB");
    sortSegments(input);
    std::cout << input;
}