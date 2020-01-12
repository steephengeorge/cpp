// Define specializations for the Traits class template here.
template <>
struct Traits<Fruit>{
     static std::string name ( int index){
        switch(static_cast<Fruit>(index)){
           case Fruit::apple:
                       return "apple";
                       break;
           case Fruit::orange: 
                       return "orange";
                       break;
           case Fruit::pear: 
                       return "pear";
                       break;
           default:
                       return "unknown";
        }
        
    }
};

template <>
struct Traits <Color>{
    static std::string name ( int index){
        switch(static_cast<Color> (index)){
            case Color::red:
                 return "red";
                 break;
            case Color::green:
                 return "green";
                 break;
            case Color::orange:
                 return "orange";
                 break;
            default:
                 return "unknown";
        }
    }
};