//Write your code here

struct ooops : std::exception {
  const char* what() const noexcept {return "n and p should be non-negative";}
};

class Calculator{
    private:
        ooops e;
    public:
    int power(int n,int p){
        if( n < 0 || p < 0){
           throw(e);
         }
        if( p == 0) return 1;
        int result= n;
        while( p-1 > 0){
            result *= n;
            --p;
        }
        return result;
    }
};