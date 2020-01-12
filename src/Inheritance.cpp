class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
         Student(std::string& firstName, std::string& lastName, int id, std::vector<int>& scores )
                  :Person(firstName, lastName,id) {
                 
              for( int i =0 ; i <scores.size(); ++i)
                 testScores.push_back(scores[i]);
            
         }
         char calculate(){
             int addition = 0;
             for( auto&x : testScores)
             {
                 addition += x;
             }
             int sum =(int) addition/testScores.size();
             char result = 'K';
             if(sum <=100 && sum >=90 )
                 result = 'O';
             else if( sum < 90 && sum >= 80 )
                 result =  'E';
             else if( sum < 80 && sum >= 70)
                 result =  'A';
             else if ( sum < 70 && sum >= 55)
                 result =  'P';
             else if ( sum < 55 && sum >= 40)
                 result =  'D';
              else if ( sum < 40)
                 result =  'T';
             
              return result;
         }
  		// Write your constructor
  
  		// Write char calculate()
};