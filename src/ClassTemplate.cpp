/*Write the class AddElements here*/
template<typename T>
class AddElements{
    private:
        T ele;
    public:
    AddElements(T x):ele(x){}
    T add( T second){
        return this->ele+ second;
    }
};
template <> 
class AddElements<std::string>{
    private:
      std::string ele;
    public:
    AddElements(std::string& x): ele(x){}
    std::string concatenate( std::string& second ){
        return this->ele+ second;
    }
};
