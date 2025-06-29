class Solution {
  public:
    int total=0;

    void dfs(int node,int dest,vector<int> adj[],vector<bool>& vis){
        if(node==dest){
            total++;
            return;
        }
        vis[node]=true;
        for(int nbr:adj[node]){
            if(!vis[nbr]){
                dfs(nbr,dest,adj,vis);
            }
        }
        vis[node]=false;
    }
    
    
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<bool> vis(V,false);
        total=0;
        dfs(source,destination,adj,vis);
        return total;
    }
};