// 二叉树的后序遍历
// 递归法 
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
    void getNodeVal(TreeNode* root, vector<int>& re)
    {
        if(!root)
            return;
        getNodeVal(root->left,re);
        getNodeVal(root->right,re);
        re.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        getNodeVal(root,re);
        return re;
    }
};

// 迭代法 
// 先序遍历为根-左-右，后续遍历为左-右-根 
// 按照根-右-左的顺序进行先序遍历，然后倒置，即可得到后续遍历 
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
    void visitAlongRightBranch(TreeNode* root, stack<TreeNode*>& s, stack<int>& num)
    {
        while(root)
        {
            num.push(root->val);
            s.push(root->left);
            root = root->right;
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> s;
        stack<int> temp;
        while(true)
        {
            visitAlongRightBranch(root,s,temp);
            if (s.empty())
                break;
            root = s.top();
            s.pop();
        }
        while(!temp.empty())
        {
            re.push_back(temp.top());
            temp.pop();
        }
        return re;
    }
};
