#ifndef INPUTSTREAM_H 
#include "inputStream.h"
#endif

inputStream::inputStream(const std::string& absolutePath)
{
     file.open(absolutePath);
     streamHandle = std::istream_iterator<std::string>(file);
}
bool inputStream::hasNext()
{
     return (streamHandle != eos);
}

double inputStream::getNext()
{
     //If it is NAN we need to handle seperately
     if(*streamHandle == "NAN")
     {
          ++streamHandle;
          return NAN;
     }
     else
     {
           std::string value = *streamHandle++;
           //converting std::string to double
           return std::stod(value);
     }
}

