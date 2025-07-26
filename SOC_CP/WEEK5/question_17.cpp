class TrieNode{
  public:
    TrieNode *child[52]={};
    bool isWord=false;
    string word="";
};

int idx(char c){
    if(c>='A'&&c<='Z')return c-'A';
    return c-'a'+26;
}

void insert(TrieNode *root,string &word){
    TrieNode *node=root;
    for(char c:word){
        int i=idx(c);
        if(!node->child[i])node->child[i]=new TrieNode();
        node=node->child[i];
    }
    node->isWord=true;
    node->word=word;
}

void dfs(int i,int j,vector<vector<char>> &board,TrieNode *node,vector<string> &res,vector<vector<bool>> &vis){
    char c=board[i][j];
    TrieNode *next=node->child[idx(c)];
    if(!next)return;
    if(next->isWord){
        res.push_back(next->word);
        next->isWord=false;
    }

    vis[i][j]=true;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int x=i+dx,y=j+dy;
            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&!vis[x][y]){
                dfs(x,y,board,next,res,vis);
            }
        }
    }
    vis[i][j]=false;
}

class Solution {
  public:
    vector<string> wordBoggle(vector<vector<char> >& board,
                              vector<string>& dictionary) {
        // Code here

        TrieNode *root=new TrieNode();
        for(auto &word:dictionary){
            insert(root,word);
        }

        int R=board.size(),C=board[0].size();
        vector<vector<bool>> vis(R,vector<bool>(C,false));
        vector<string> res;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                dfs(i,j,board,root,res,vis);
            }
        }

        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};