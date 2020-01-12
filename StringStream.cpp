#include <sstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function 
   std::vector<int> result;
   std::istringstream iss(str);
   std::string num;
   while( std::getline(iss, num, ',' )){
       result.push_back(stoi(num));
   }
   
   return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
