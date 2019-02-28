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
    bool isSame(TreeNode* lt, TreeNode* rt)
    {
        if (!lt) // 评论里一位大神的写法，感觉很有意思，而且很简洁 
            return !rt;
        else if(!rt)
            return !lt;
        else if(lt->val == rt->val)
            return isSame(lt->left, rt->right)&&isSame(lt->right, rt->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root, root);
        
    }
};
