#include <iostream>
#include <string>
#include <vector>
#include<algorithm>


using namespace std;    

int coverPoints(vector<int> &X, vector<int> &Y)
{
    int currentX=X[0];
    int currentY=Y[0];
    int steps=0;
    for(int i =1;i < X.size() ; ++i)
    {
      steps+=std::max( std::abs(currentX-X[i]), std::abs(currentY-Y[i]));
      currentX=X[i];
      currentY=Y[i];
    }
    return steps;
}

int main()
{
    std::vector<int> X= {0, 2,3};
    std::vector<int> Y={0, 2,5};
    std::cout<<coverPoints(X,Y);
         
}
