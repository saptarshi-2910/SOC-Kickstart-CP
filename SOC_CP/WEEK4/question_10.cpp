class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> order;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(int nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }

        if(order.size()==n) return order;
        return {};
    }
};