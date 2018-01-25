#include <string>
#include <algorithm>
#include <iostream>

//test "1234"
//test "09867"
//test "-67890"
//test "99999"
//test "00000"
//test "11111"
//Assumption: not expecting octal numbers
std::string intToString(int val){

    bool isNegative = false;
    if( val < 0)
        isNegative = true;

    std::string s;
    do
    {
        s += '0' + std::abs(val % 10);
        val /= 10;
    }while(val);

    if(isNegative)
       s += '-';
    std::reverse(s.begin(), s.end());
    return s;
}

int main()
{
    std::cout << intToString(1234) << "\n";
    std::cout << intToString(-67890) << "\n";
    std::cout << intToString(00000) << "\n";
    std::cout << intToString(11111) << "\n";
    //Octal numbers, result wrong
    std::cout << intToString(06767) << "\n";
}
