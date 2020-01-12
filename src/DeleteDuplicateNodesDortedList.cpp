/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
   Node* current = head;
   Node* prev;
   while(current)
   {
       int first = current->data;
       prev = current;
       current = current->next;
       if( current)
       {
           int second = current->data;
       
           if( first == second)
           {
               prev->next = current->next;
               Node* temp = current;
               delete temp;
               current = prev;
            }
        }
   }
   return head;
}
