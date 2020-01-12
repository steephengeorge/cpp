/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node* currentA  = headA;
    Node* currentB = headB;
    while( currentA && currentB)
    {
        if( currentA->data != currentB->data)
        {
            return 0;
        }
        currentA = currentA->next;
        currentB = currentB->next;
    }
    return ( currentA == nullptr && currentB == nullptr) ? 1 : 0; 
  
  
}
