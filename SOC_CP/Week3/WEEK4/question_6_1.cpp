class Solution {
  public:
    bool dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>& visited){
        visited[node]=true;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,node,adj,visited)) return true;
            } else if(neighbor != parent){
                return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
    vector<vector<int>> adj(V);
    for(auto& edge:edges){
        int u=edge[0], v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        }

    vector<bool> visited(V, false);
    for (int i=0;i<V;++i){
        if (!visited[i]){
            if (dfs(i,-1,adj,visited)) return true;
            }
        }

        return false;
    }
};