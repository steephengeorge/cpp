      Node* insert(Node *head,int data)
      {
          //Complete this method
          if( head == NULL){
              head = new Node(data);
              return head;
          }
          Node * tail = head -> next;  
          Node * prev = head;
          while( tail  != NULL)
          {
             prev = tail;
             tail = tail->next;
          }
          
          prev->next = new Node(data);
          return head;
      }