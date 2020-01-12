#include <stack>
/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
  Node* current = head;
  Node* prev = nullptr;
  Node* coming = nullptr;
    
  
  while(current)
  {      
      coming= current->next;
      current->next = prev;
      prev = current;
      current = coming;
  } 
  head = prev;
  return head;
 
}
