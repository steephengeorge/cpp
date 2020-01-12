#include<algorithm>
// Enter your code fboolreversed_binary_value<bool


template <bool... digits>
int reversed_binary_value() {    
    int result =0;
    auto values = {digits...};    
    int counter = 1;
    std::for_each(values.begin(), values.end(), [&](bool n){  if(n) result += counter; counter*=2;});
    return result;
}


