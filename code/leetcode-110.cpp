//110-Æ½ºâ¶þ²æÊ÷
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        else
            return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        else if(abs(height(root->left)-height(root->right))>1)
            return false;
        else return isBalanced(root->left)&&isBalanced(root->right);
    }
}; 
