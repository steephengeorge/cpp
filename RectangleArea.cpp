
/*
 * Create classes Rectanlge and RectangleArea
 */
class Rectangle{
     public:
       int width;
       int height;
   
      void display(){
          std::cout << width <<" "<<height<<"\n";
      }
};

class RectangleArea:public Rectangle{
    public:
        void read_input(){
            std::cin >> width >> height;
        }
        void display(){
            std::cout<< width * height;
        }
};
