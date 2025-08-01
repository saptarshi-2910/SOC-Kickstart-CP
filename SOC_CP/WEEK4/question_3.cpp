class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> adj(V); 

        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }

        return adj;
    }
};