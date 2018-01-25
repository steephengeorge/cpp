#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <deque>

template <typename T>
class stack
{
    public:
            stack()
            {
            }
            void pop()
            {
              container.pop_front();
            }
            T top()
            {
                return container.front();
            }
            void push(T ele)
            {
                container.push_front(ele);
            }

    private:
        std::deque<T> container;
};

int main()
{
   stack<int> st;
   st.push(1);
   st.push(2);
   st.push(3);
   std::cout << st.top();
   st.pop();
   std::cout << st.top();
}
