/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
  Node* temp = new Node;
  temp->data = data;
  if(head == nullptr && position == 0)
  {
      temp->next = nullptr;
      head = temp;
      return head;
  }
    
  if( position == 0)
  {
    temp->next = head;
    head = temp;
    return head;
  }
  
  Node* current = head;
    
  while(current)
  {
       if( --position == 0)
       {
            temp->next = current->next;
            current-> next = temp;            
            break;           
       }
       current = current->next;
   }
   return head;
}
