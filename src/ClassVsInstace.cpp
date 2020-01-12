class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){            
         age = initialAge;
         if( initialAge < 0)
         {                    
            age = 0;
            std::cout << "Age is not valid, setting age to 0.\n";
         }
    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        if(age < 13)
        {
            std::cout << "You are young.\n";
        }
        else if( age >= 13  && age < 18)
        {
            std::cout<<"You are a teenager.\n";
        }
        else 
        {
            std::cout<<"You are old.\n";
        }

    }

    void Person::yearPasses(){
        ++age;
        // Increment the age of the person in here

    }