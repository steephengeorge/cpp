//#include<string>


class Person{
    private:
    
    public:
      char name[100];
      int age;
      
     virtual void getdata()=0;
     virtual void putdata()=0;
};



class Professor:public Person{
  
    
  public:
    int publications; 
    static int pid ;
     void getdata(){
         std::cin >> this->name>> this->age>> this->publications;
     }
     void putdata(){
         std::cout<< name <<" "<< age <<" "<< publications <<" "<< pid++ << "\n";
     }
};

class Student:public Person{
  private :
    
  public:
     int  marks[6];
     static int sid ;
     void getdata(){
          std::cin >> name>> age >> marks[0] >> marks[1] >> marks[2]
                                 >> marks[3] >> marks[4] >> marks[5];
     }
     void putdata(){
         
         std::cout << name <<" "<< age << " "<< std::accumulate( marks, marks+6, 0)<<" "<<sid++<< "\n";  
     }
};

int Professor::pid = 1;
int Student::sid = 1;
