#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    double mealCost = 0.0;
    double tip = 0.0;
    double tax = 0.0;
    std::cin >>  mealCost;
    std::cin >> tip;
    std::cin >> tax;
    
    double totalCost = mealCost*((100+tax+tip)/100);
    std::cout << "The total meal cost is " << std::round(totalCost) << " dollars.";
    return 0;
}
