#ifndef STATISTICSGENERATOR_H 
#define STATISTICSGENERATOR_H 

#include <deque>
#include <numeric>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include "statistics.h"

struct book{
   double sum;
   double max;
   book():sum(0.0), max(std::numeric_limits<double>::min()){}
};
class statisticsGenerator
{
    public:
        //Constructor
        statisticsGenerator(std::vector<int>& windowSize);
        // Get the current statistics.
        std::vector<statistics>  getNext(double);        
    private:
 	//Insert new value into the Window
        void insertIntoWindow(const int index,const  double value);				
        //Get count of Windows
        int countOfWindows();
        //Pop oldest value from the window
        void popFromWindow(const int index);
        double popValueFromWindow(const int index);
        //Get current Window Size
	int getCurrentWindowSize(const int index);
        //Get all elements from the window 
        std::deque<double> getWindow(const int index);
    	int getWindowSize(const int index);
	std::vector<int> windowSizes;
	std::vector< std::deque<double> > windows;		 
        std::vector< book> bookKeeper;
};

#endif
    

