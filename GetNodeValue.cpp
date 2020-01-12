#include <vector>
/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  Node* current = head;
  std::vector<int> vec;
  int count = 0;
  while(current)
  {
      vec.push_back(current->data);
      current = current->next;           
  }
  return vec[vec.size()-positionFromTail-1];
    
}
