// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &edge:edges) {
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> dist(V,INT_MAX);
        dist[src]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            for(auto &nbr:adj[u]){
                int v=nbr.first,w=nbr.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }

        return dist;
    }
};


