// User function Template for C++
class Solution {
  public:
    void topoSort(int node,vector<vector<pair<int,int>>> &adj,vector<bool> &vis,stack<int> &st){
        vis[node]=true;
        for(auto &nbr:adj[node]){
            if(!vis[nbr.first]){
                topoSort(nbr.first,adj,vis,st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<bool> vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }

        vector<int> dist(V,1e8);
        dist[0]=0;
        while(!st.empty()){
            int u=st.top();
            st.pop();
            if(dist[u]!=1e8){
                for(auto &nbr:adj[u]){
                    int v=nbr.first,w=nbr.second;
                    if(dist[u]+w<dist[v]){
                        dist[v]=dist[u]+w;
                    }
                }
            }
        }

        for(int i=0;i<V;i++){
            if(dist[i]==1e8)dist[i]=-1;
        }

        return dist;
    }
};
