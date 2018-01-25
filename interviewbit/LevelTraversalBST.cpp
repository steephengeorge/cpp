/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void levelFind(TreeNode* root, int depth, std::vector<std::vector<int>> & result)
{
    if(!root)
    {
        return;
    }
    if(result.size() == depth)
    {
        result.push_back(std::vector<int>());
    }

    result[depth].push_back(root->val);
    if(root->left)
        levelFind(root->left, depth + 1, result);
    if(root->right)
        levelFind(root->right, depth + 1, result);
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    std::vector<std::vector<int>> result;
    levelFind(A, 0, result);
    return result;
}
