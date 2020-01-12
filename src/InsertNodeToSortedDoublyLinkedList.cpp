/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node* dataNode= new Node();
    dataNode->data = data;
    dataNode->prev = NULL;
    dataNode->next = NULL;
    
    //Head is null
    if(!head)
    {
        head = dataNode;
        return head;
    }
    //Head data is greater than data
    if( head->data > data)
    {
        dataNode->next = head;
        head->prev = dataNode;
        return dataNode;
    }
    
    Node* current = head;
    while(current)
    {        
        Node* prev = current;        
        current = current->next;
        //After taking Next if current Node is NULL
        if(!current)
        {
            current = dataNode;
            dataNode->prev = prev;
            prev->next = current;
            break;
        }
        if( current &&  data < current->data)
        {
            prev->next = dataNode;
            dataNode->next = current;
            dataNode->prev = prev;
            current->prev = dataNode;
            break;
        }
    }
    return head;
}
