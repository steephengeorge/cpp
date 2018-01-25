/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool isValidBSTUtil(TreeNode* A, int min, int max)
 {
     if(!A)
     {
         return true;
     }
     if( A->val > min &&
         A->val < max &&
         isValidBSTUtil(A->left, min, A->val) &&
         isValidBSTUtil(A->right, A->val, max))
         return true;
     else
         return false;

 }
int Solution::isValidBST(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     return isValidBSTUtil(A,std::numeric_limits<int>::min(), std::numeric_limits<int>::max() );

}
