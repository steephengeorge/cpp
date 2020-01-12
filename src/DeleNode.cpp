/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    // Complete this method
    Node* temp = head;
    if(position == 0)
    {        
        head = head->next;
        delete temp;
        return head;
    }
    Node* current = head;
    Node* prev;
    while(position)
    {  
        prev = current;
        current = current->next;
        --position;
    }
    temp = current;
    prev-> next = current->next;    
    delete temp;
    return head;
}
