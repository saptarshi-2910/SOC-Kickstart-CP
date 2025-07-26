class Solution{
  public:
    double maxProbability(int n,vector<vector<int>> &edges,vector<double> &succProb,int start,int end){
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double p=succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        vector<double> prob(n,0.0);
        prob[start]=1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});

        while(!pq.empty()){
            double p=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(u==end)return p;

            for(auto &nbr:adj[u]){
                int v=nbr.first;
                double w=nbr.second;
                if(p*w>prob[v]){
                    prob[v]=p*w;
                    pq.push({prob[v],v});
                }
            }
        }

        return 0.0;
    }
};
