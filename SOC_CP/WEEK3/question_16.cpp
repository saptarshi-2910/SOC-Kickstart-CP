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
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& nodes) {
        if (!root) return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }

    TreeNode* buildBST(vector<int>& nodes,int left,int right){
        if (left>right) return nullptr;
        int mid= left+(right-left)/2;
        TreeNode* root =new TreeNode(nodes[mid]);
        root->left= buildBST(nodes,left,mid-1);
        root->right= buildBST(nodes,mid+1,right);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nodes;
        inorder(root,nodes);
        return buildBST(nodes,0,nodes.size()-1);
    }
};
