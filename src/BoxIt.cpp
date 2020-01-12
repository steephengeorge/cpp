
//Implement the class Box  
class Box{
    
//l,b,h are integers representing the dimensions of the box
 private :
    int l;
    int b;
    int h;

 public:
    Box():l(0),b(0),h(0){ ++BoxesCreated; }
    Box(int l, int b, int h){
        this->l = l;
        this->b = b;
        this->h = h;
        ++BoxesCreated;
    }
    Box(const Box& x){
        this->l = x.l;
        this->b = x.b;
        this->h = x.h;
        ++BoxesCreated;
    }
   
    Box& operator=(const Box& x){
        l = x.l;
        b = x.b;
        h = x.h;
        return *this;
    }
    ~ Box(){++BoxesDestroyed;}
    int getLength(){
        return l;
    }
    int getBreadth (){
        return b;
    }
    int getHeight (){
        return h;
    }
     unsigned long long int CalculateVolume(){
        return (long long) l*b*h;
    }
    bool operator <( Box& b){
         if( this->l < b.l)
             return true;
         else if( this->l == b.l && this->b < b.l)
             return true;
         else if( this->l == b.l && this->b == b.l && this->h < b.h  )
             return true;
         else
             return false;
    }
   
};

 std::ostream& operator << ( std::ostream& os , Box b){
        os << b.getLength() <<" "<< b.getBreadth() << " "<<b.getHeight();
        return os;
    }
// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);

// Destructor
// ~Box()
// {

// }

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box &b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)

