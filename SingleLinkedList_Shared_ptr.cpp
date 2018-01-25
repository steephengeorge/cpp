// Write a function to swap two bits of an integer, at indices i and j

// Write a function to reverse the sequence of a singly-linked list composed of Node objects, given Node *head

#include <iostream>
#include <memory>

template<typename T>
class Node
{
   private:
      const T data;
   public:
      explicit Node( const T& d ) : data( d ), next(nullptr) {}

      std::shared_ptr<Node<T>> next;
      T getData(){
        return data;
      }
  
};



template<typename T>
std::shared_ptr<T> reverseLinkedList(std::shared_ptr<T>& head)
{
    std::shared_ptr<T> tmp = head;
    std::shared_ptr<T> prev = tmp;
    tmp = tmp->next;
       
    while(tmp)
    {        
        std::shared_ptr<T> next = tmp->next;
        tmp->next = prev;     
        prev = tmp;
        tmp = next;
         
     
        //else
        
        //tmp->next =nullptr;
        //{
            //tmp->next = prev;
            //->next = nullptr;
            //break;
            
        //}
      
    }
    //next->next = prev;
    
    //tmp->next = prev;
    head->next = nullptr;
    return prev;  
    
}


int main()
{
   /*Node<int>* Node1 = new Node<int>(5);
   Node<int>* Node2 = new Node<int>(6);
   Node<int>* Node3 = new Node<int>(7);
   Node<int>* Node4 = new Node<int>(8);*/
   
   std::shared_ptr<Node<int>> Node1 = std::make_shared<Node<int>>(5);
   std::shared_ptr<Node<int>> Node2 = std::make_shared<Node<int>>(6);
   std::shared_ptr<Node<int>> Node3 = std::make_shared<Node<int>>(7);
   std::shared_ptr<Node<int>> Node4 = std::make_shared<Node<int>>(8);
   Node1->next = Node2;
   Node2->next = Node3;
   Node3->next = Node4;
    
   std::shared_ptr<Node<int>> Node5 = reverseLinkedList<Node<int>>(Node1);
   
   while( Node5)
   {
       std::cout << Node5->getData();
       Node5 = Node5->next;
   }
}