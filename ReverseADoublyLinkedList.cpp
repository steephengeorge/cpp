/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head) {
   Node* temp = head;
   Node* newHead = head;
   while(temp)
   {
       Node* next = temp->next;
       temp->next = temp->prev;
       temp->prev = next;
       newHead = temp;
       
       temp = temp->prev;
   }
   return newHead;
    
}