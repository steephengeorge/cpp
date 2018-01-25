
#ifndef INPUTSTREAM_H 
#define INPUTSTREAM_H  

#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <cmath>

class inputStream
{
    public:
        //constructor
        inputStream(const std::string&);
        //Returns true if more elements are available
        bool hasNext();
        //Get the next element in the stream
        double getNext();

    private:
        std::fstream file;
        std::istream_iterator<std::string> streamHandle;
        std::istream_iterator<std::string> eos; //End of the iterator
};

#endif
