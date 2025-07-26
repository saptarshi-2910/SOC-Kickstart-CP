// User function template for C++
class TrieNode{
  public:
    TrieNode *child[26]={};
    bool isWord=false;
};

void insert(TrieNode *root,const string &s){
    TrieNode *node=root;
    for(char c:s){
        int i=c-'a';
        if(!node->child[i])node->child[i]=new TrieNode();
        node=node->child[i];
    }
    node->isWord=true;
}

bool search(TrieNode *root,const string &s,int i,int j){
    TrieNode *node=root;
    for(int k=i;k<=j;k++){
        int idx=s[k]-'a';
        if(!node->child[idx])return false;
        node=node->child[idx];
    }
    return node->isWord;
}

class Solution {
  public:
    // A : given string to search
    // B : vector of available strings

    int wordBreak(string A, vector<string> &B) {
        // code here
        TrieNode *root=new TrieNode();
        for(auto &w:B)insert(root,w);

        int n=A.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&search(root,A,j,i-1)){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[n];
    }
};