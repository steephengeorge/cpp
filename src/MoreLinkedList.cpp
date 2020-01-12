          Node* removeDuplicates(Node *head)
          {
            std::vector<int> mySet;
            Node * curr = head;
            Node * prev = NULL;
            //Write your code here
            while( curr)
            {
                
                if( std::find(mySet.begin(), mySet.end(),curr->data) != mySet.end())
                {
                    prev-> next = curr->next;
                    curr = curr->next;
                    //mySet.push_back()
                    continue;
                    
                }
                mySet.push_back(curr->data);
                prev = curr;
                curr = curr->next;
            }
             return head;
          }