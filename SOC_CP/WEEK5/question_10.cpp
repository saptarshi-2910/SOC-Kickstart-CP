class Solution {
    void dfs(int u,int parent,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &disc,vector<int> &low,bool &isBridge,int c,int d,int &timer){
        vis[u]=true;
        disc[u]=low[u]=timer++;
        for(int v:adj[u]){
            if(v==parent)continue;
            if(!vis[v]){
                dfs(v,u,adj,vis,disc,low,isBridge,c,d,timer);
                low[u]=min(low[u],low[v]);
                if(low[v]>disc[u]){
                    if((u==c&&v==d)||(u==d&&v==c))isBridge=true;
                }
            }else{
                low[u]=min(low[u],disc[v]);
            }
        }
    }

  public:
    bool isBridge(int V,vector<vector<int>> &edges,int c,int d){
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(V,false);
        vector<int> disc(V,-1),low(V,-1);
        int timer=0;
        bool isBridge=false;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,disc,low,isBridge,c,d,timer);
            }
        }

        return isBridge;
    }
};