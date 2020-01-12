/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* current = head;
    Node* doubleSpeed = head;
    if( current)
        doubleSpeed = current->next;
    if(doubleSpeed )
        doubleSpeed = doubleSpeed->next;
    while( doubleSpeed)
    {
        if( doubleSpeed == current)
        {
            return true;
        }
        current = current->next;
        
        if(doubleSpeed )
          doubleSpeed = doubleSpeed->next;
        if(doubleSpeed )
          doubleSpeed = doubleSpeed->next;        
    }    
    return false;    
    
}
