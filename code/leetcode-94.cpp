// 二叉树中序遍历
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
        if (!root)
            return;
        getNodeVal(root->left,re);
        re.push_back(root->val);
        getNodeVal(root->right,re);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> re;
        getNodeVal(root,re);
        return re;
        
    }
};

// 迭代法
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
    void findStart(TreeNode* root, stack<TreeNode*>& s) //沿左子树找到中序遍历的起点
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> s; 
        while (true)
        {        
            findStart(root, s);
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            re.push_back(root->val);
            root = root->right;
        }
    return re;   
    }
};
