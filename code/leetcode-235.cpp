// 二叉搜索树
// 它或者是一棵空树，或者是具有下列性质的二叉树： 
// 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
// 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
// 它的左、右子树也分别为二叉搜索树。

// 当输入p和q的值一个小于等于root的值，一个大于等于root的值时，则root则为最小公共祖先。
// 当p和q的值都小于root时，公共祖先处于root的左子树
// 当p和q的值都大于root时，公共祖先处于root的右子树 
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((p->val-root->val)*(q->val-root->val)<=0)
            return root;
        else if(p->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        else
            return lowestCommonAncestor(root->left,p,q);
    }
}; 
