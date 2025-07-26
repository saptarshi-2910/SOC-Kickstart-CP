/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void reverseInorder(Node* root,int& k,int& ans){
        if(!root||k==0) return;
        reverseInorder(root->right,k,ans);
        if(--k == 0){
            ans= root->data;
            return;
        }
        reverseInorder(root->left,k,ans);
    }
    
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans=-1;
        reverseInorder(root,k,ans);
        return ans;
    }
};