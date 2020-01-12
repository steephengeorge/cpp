#include <iostream>
#include <list>

using namespace std;

class Solution {
    //Write your code here
    std::list<char> queue;
    std::list<char> stack;
    public:
    void pushCharacter(char ch){
        stack.push_back(ch);
    }
    void enqueueCharacter(char ch) {
        queue.push_back(ch);
    }
    char popCharacter(){
       char r = stack.back();
       stack.pop_back();
       return r;
    }
    char dequeueCharacter(){
       char r = queue.front();
       queue.pop_front();
       return r;
    } 
    

};
