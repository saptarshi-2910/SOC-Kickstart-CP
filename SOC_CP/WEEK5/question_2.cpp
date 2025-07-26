// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;

        for(int i=1;i<V;i++){
            for(auto &e:edges){
                int u=e[0],v=e[1],w=e[2];
                if(dist[u]!=1e8&&dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }

        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(dist[u]!=1e8&&dist[u]+w<dist[v]){
                return {-1};
            }
        }

        return dist;
    }
};