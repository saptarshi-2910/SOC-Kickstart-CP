/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
  public:
    void dfs(TreeNode* root,vector<int>& res){
        if(!root)return;
        res.push_back(root->val);
        dfs(root->left,res);
        dfs(root->right,res);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        dfs(root,res);
        return res;
    }
};
