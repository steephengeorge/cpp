class LRUCache: public Cache{
    public:
    LRUCache(int cap): Cache(){   
        cp= cap;
        
    }
    void set(int  key, int value){              
        
        if( cp >= mp.size()+1){
            if(head == NULL){
                Node *node = new Node(key,value);
                head = tail = node;
                head->next = head->prev = tail->next = tail->prev = NULL;
                mp[key] = node;
            }
            else{
                Node *node= new Node(key,value);
                node->next = head;
                head-> prev = node;
                node->prev = tail;
                tail->next = node;                
                head = node;
                
                mp[key] = node;
            }            
        }
        else{
            Node * node = tail;
            tail = tail->prev;
            mp.erase(node->key);
            delete node;
            
            node= new Node(key,value);
            node->next = head;
            head-> prev = node;
            node->prev = tail;
            tail->next = node;                
            head = node;   
            
            mp[key] = node;
       }          
   }
   int get(int key){
       auto found = mp.find(key);
       if( found != mp.end()){
           if( found->second->prev && found->second->next ){
               found->second->prev->next= found->second->next;
               found->second->next->prev = found->second->next;               
               
               found->second->prev = tail;           
               found->second->next = head;         
           }
           tail->next = found->second;
           head->prev = found->second;        
           head = found->second;
           return found->second->value;
       }
       return -1;
   }
};