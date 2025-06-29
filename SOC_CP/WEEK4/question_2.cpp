class Solution {
  public:
  
    void dfsUtil(int node,vector<vector<int>>& adj,vector<bool>& visited,vector<int>& dfs_result){
        visited[node]=true;
        dfs_result.push_back(node);

        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                dfsUtil(neighbor,adj,visited,dfs_result);
            }
        }
    }
    
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<bool> visited(V,false);
        vector<int> dfs_result;

        dfsUtil(0,adj,visited,dfs_result);
        return dfs_result;   
    }
};