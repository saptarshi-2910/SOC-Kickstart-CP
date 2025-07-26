class TrieNode{
  public:
    TrieNode *child[26]={};
    bool isWord=false;
    string word="";
};

void insert(TrieNode *root,string &s){
    TrieNode *node=root;
    for(char c:s){
        int i=c-'A';
        if(!node->child[i])node->child[i]=new TrieNode();
        node=node->child[i];
    }
    node->isWord=true;
    node->word=s;
}

void dfs(int i,int j,vector<vector<char>> &map,TrieNode *node,vector<string> &res,vector<vector<bool>> &vis){
    char c=map[i][j];
    int id=c-'A';
    TrieNode *next=node->child[id];
    if(!next)return;
    if(next->isWord){
        res.push_back(next->word);
        next->isWord=false;
    }

    vis[i][j]=true;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            if(dx==0&&dy==0)continue;
            int x=i+dx,y=j+dy;
            if(x>=0&&x<map.size()&&y>=0&&y<map[0].size()&&!vis[x][y]){
                dfs(x,y,map,next,res,vis);
            }
        }
    }
    vis[i][j]=false;
}

class Solution {
  public:
    vector<string> openGates(vector<vector<char> >& map, vector<string>& gate_names) {
        // Code here
        TrieNode *root=new TrieNode();
        unordered_set<string> seen;
        for(auto &s:gate_names){
            if(!seen.count(s)){
                insert(root,s);
                seen.insert(s);
            }
        }

        int r=map.size(),c=map[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        vector<string> res;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dfs(i,j,map,root,res,vis);
            }
        }

        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};