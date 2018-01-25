/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* Find(TreeNode* root, int data)
 {
     while( root != nullptr && root->val != data)
     {
         if( data < root->val)
         {
             root = root->left;
         }
         else
         {
             root = root->right;
         }
     }
     if( root != nullptr && root->val == data )
     {
         return root;
     }
     return nullptr;
 }

 TreeNode* FindMin(TreeNode* root)
 {
     while( root->left != nullptr)
     {
         root = root->left;
     }
     return root;
 }
TreeNode* FindSuccessor(TreeNode* root, int data)
{
    TreeNode* ancestor = root;
    TreeNode* successor = nullptr;
    while(ancestor != nullptr && data != ancestor->val )
    {
        if(data < ancestor->val)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
        {
            ancestor = ancestor->right;
        }
    }
    return successor;
}
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* current = Find(A,B);
    if(!current)
    {
        return nullptr;
    }
    if(current->right != nullptr)
    {
        return FindMin(current->right);
    }
    else
    {
        return FindSuccessor(A, B );
    }
}
