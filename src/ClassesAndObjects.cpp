// Write your Student class here
class Student{
  std::vector<int> scores;
  public:
     void input(){
         int num;
         int n = 5;
         
         while(n > 0){
             std::cin >> num;
             scores.push_back(num);
             --n;
         }        
     }
     
     int calculateTotalScore(){
         return (std::accumulate(scores.begin(), scores.end(),0));
     }
};