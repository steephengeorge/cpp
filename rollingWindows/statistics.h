#ifndef STATISTICS_H 
#define STATISTICS_H 

#include <cmath>

struct statistics
{
    bool valid; // true only if mean and max fields are valid
    double mean;
    double max;
    statistics():valid(true), mean(NAN), max(NAN) {}
};

#endif
