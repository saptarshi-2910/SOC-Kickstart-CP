class Solution{
  public:
    int networkDelayTime(vector<vector<int>> &times,int n,int k){
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }

        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u])continue;
            for(auto &nbr:adj[u]){
                int v=nbr.first,w=nbr.second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            ans=max(ans,dist[i]);
        }

        return ans;
    }
};
