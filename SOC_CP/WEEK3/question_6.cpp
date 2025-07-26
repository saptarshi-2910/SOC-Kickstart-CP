class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
        // Your code here
    bool isBSTUtil(Node* root,long long minVal,long long maxVal){
        if(!root) return true;
        if(root->data<=minVal || root->data>=maxVal) return false;
        return isBSTUtil(root->left,minVal,root->data) && isBSTUtil(root->right,root->data,maxVal);
    }

    bool isBST(Node* root){
        return isBSTUtil(root,LLONG_MIN,LLONG_MAX);
    }
};
