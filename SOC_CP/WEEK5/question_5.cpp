class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<bool> vis(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int mstWeight=0;

        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            int w=p.first,u=p.second;
            if(vis[u])continue;
            vis[u]=true;
            mstWeight+=w;
            for(auto &nbr:adj[u]){
                int v=nbr[0],wt=nbr[1];
                if(!vis[v]){
                    pq.push({wt,v});
                }
            }
        }

        return mstWeight;
    }
};