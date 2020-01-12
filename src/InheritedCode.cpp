/* Define the exception here */

class BadLengthException:public std::exception{
    int length;
    public:
    BadLengthException(int n){
        length = n;
    }
    const char* what() const noexcept {return std::to_string(length).c_str();}
};