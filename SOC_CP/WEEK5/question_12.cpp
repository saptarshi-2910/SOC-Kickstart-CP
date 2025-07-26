class Solution {
  public:
    void dfs(int u,int parent,vector<int> adj[],vector<bool> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<bool> &isArt){
        vis[u]=true;
        tin[u]=low[u]=timer++;
        int children=0;
        for(int v:adj[u]){
            if(v==parent)continue;
            if(!vis[v]){
                dfs(v,u,adj,vis,tin,low,timer,isArt);
                low[u]=min(low[u],low[v]);
                if(low[v]>=tin[u]&&parent!=-1)isArt[u]=true;
                children++;
            }else{
                low[u]=min(low[u],tin[v]);
            }
        }
        if(parent==-1&&children>1)isArt[u]=true;
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(V,false),isArt(V,false);
        vector<int> tin(V,-1),low(V,-1);
        int timer=0;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,tin,low,timer,isArt);
            }
        }

        vector<int> res;
        for(int i=0;i<V;i++){
            if(isArt[i])res.push_back(i);
        }
        if(res.empty())return {-1};
        return res;
    }
};