//Write MyBook class
class MyBook:public Book{
  private:
    int price;
  public:
  MyBook(std::string title, std::string author, int price):Book(title,author){
      this->price = price;
  }  
  void display(){
      std::cout<<"Title: "<<title<<"\n";
      std::cout<<"Author: "<<author<<"\n";
      std::cout<<"Price: "<<price<<"\n";
  }
};