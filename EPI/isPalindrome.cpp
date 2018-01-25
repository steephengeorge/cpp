#include <iostream>
#include <string>

bool isPalindrome(const std::string& s)
{
    for(int i = 0, j = s.size()-1; i < j ; ++i, --j)
    {
        if(s[i] != s[j])
            return false;
    }
    return true;
}
int main()
{
    std::string s1 = "malayalam";
    std::string s2 = "kerala";

    std::cout << isPalindrome(s1) << "\n";
    std::cout << isPalindrome(s2) << "\n";
}
