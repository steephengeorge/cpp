#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    string time;
    cin >> time;
    if( time.find("AM") != std::string::npos)
    {
        std::size_t end= time.find(":");
        int hr = std::stoi(time.substr(0, end));
        if( hr == 12)
        {
            std::cout<<"00"<<time.substr(end, time.length()-4); 
            return 0;  
        }    
        std::cout<<time.substr(0, time.length()-2);
        return 0;
    }
    std::size_t end= time.find(":");
    int hr = (std::stoi(time.substr(0, end)) + 12);
    if( hr ==24)
        hr -=12;
       
    std::cout<<hr<<time.substr(end, time.length()-4);    
}