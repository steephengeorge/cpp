#include <stack>
/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  std::stack<int> store;
  Node* current = head;
  while(current)
  {
      store.push(current->data);
      current = current->next;
  }
  while( !store.empty())
  {
      std::cout << store.top()<<"\n";
      store.pop();
  }
 
}
