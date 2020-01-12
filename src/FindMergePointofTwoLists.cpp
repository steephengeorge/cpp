/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/


int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node* currentA = headA;
    Node* currentB = headB;
    
    while(currentA)
    {
        currentB = headB;
        while(currentB)
        {
            if( currentA == currentB )
            {
                return currentA->data;
            }
            currentB = currentB->next;
        }
        currentA = currentA->next;
    }
    return 0;
}
