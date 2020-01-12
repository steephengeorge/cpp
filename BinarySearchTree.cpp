		int getHeight(Node* root){
          //Write your code here
          
           if(root == NULL)
               return -1;
           int leftht = getHeight(root->left);
           int rightht = getHeight(root->right);
           return( std::max(leftht,rightht)+1);
        }

