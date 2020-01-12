/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
     // This is a "method-only" submission. 
    // You only need to complete this method  
    Node* currentA = headA;
    Node* currentB = headB;
    Node* head = headA;
    Node* current = headA;
    
    if( !currentA )
    {
        head = currentB;
        return head;
    }
    if(!currentB)
    {
        head = currentA;
        return head;
    }
    
    if( currentA->data > currentB->data )
    {
        head =currentB;
        currentB = currentB->next;
        current=head;
    }
    else
    {
        head=currentA;
        currentA = currentA->next;
        current=head;
    }
    
    while(currentA && currentB)
    {
        if( currentA->data > currentB->data )
        {
          current->next = currentB;
          currentB = currentB->next;
          current = current->next;
        }
        else
        {
          current->next = currentA;
          currentA = currentA->next;
          current = current->next;
        }
    }
    if( !currentA && currentB)
    {
        current->next = currentB;
    }
    else if(!currentB && currentA)
    {
        current->next = currentA;
    }
    return head;
}
