/*
 * Complete the function below.
 */
int findMatchingPair(string& s) {
   int result = -1;
   std::stack<char> stk;
   if(std::islower(s[0]))
       return -1;
    else
        stk.push(s[0]);

    for(size_t i= 1; i < s.size(); ++i)
    {
       char prev ='0'; // Initializing with an non alpha value;

       if(!stk.empty())
       {
          prev = stk.top();
       }


       stk.push(s[i]);
       if(!stk.empty() && std::islower(s[i]) && std::toupper(stk.top())==prev)
       {
           stk.pop();
           stk.pop();
           result = i;


           continue;
       }
       else if(std::isupper(s[i]))
       {
           continue;
       }
       else
       {
           break;
       }
    }
    return result;
}

