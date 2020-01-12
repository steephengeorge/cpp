	void levelOrder(Node * root){
      //Write your code here
        std::queue<Node*> que;
        que.push(root);
        while(!que.empty()){
         Node* cur = que.front();
         que.pop();  
        
         if( cur != NULL){
               std::cout << cur->data <<" ";
               que.push(cur->left);
               que.push(cur->right);
         }
       }
  	        
  
	}