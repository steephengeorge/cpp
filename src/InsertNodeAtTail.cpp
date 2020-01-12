/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
 
  Node* current = head;
  if(current == nullptr)
  {
      Node* temp = new Node();
      temp->next = nullptr;
      temp->data = data;
      current = temp;
      return current;
  }
  while(current->next)
  {
    current = current->next;    
  }
  Node* temp = new Node();
  temp->next = nullptr;
  temp->data = data;
  current->next = temp;
  return head;
}
