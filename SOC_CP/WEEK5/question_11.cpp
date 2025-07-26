// User function template for C++

class Solution {
    void dfs(int u,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,stack<int> &st,vector<bool> &inStack,int &time,vector<vector<int>> &res){
        disc[u]=low[u]=time++;
        st.push(u);
        inStack[u]=true;
        for(int v:adj[u]){
            if(disc[v]==-1){
                dfs(v,adj,disc,low,st,inStack,time,res);
                low[u]=min(low[u],low[v]);
            }else if(inStack[v]){
                low[u]=min(low[u],disc[v]);
            }
        }
        if(disc[u]==low[u]){
            vector<int> scc;
            while(true){
                int node=st.top();
                st.pop();
                inStack[node]=false;
                scc.push_back(node);
                if(node==u)break;
            }
            sort(scc.begin(),scc.end());
            res.push_back(scc);
        }
    }

  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        // code here
        vector<int> disc(V,-1),low(V,-1);
        vector<bool> inStack(V,false);
        stack<int> st;
        vector<vector<int>> res;
        int time=0;
        vector<vector<int>> graph(V);
        for(int u=0;u<V;u++){
            for(int v:adj[u]){
                graph[u].push_back(v);
            }
        }
        for(int i=0;i<V;i++){
            if(disc[i]==-1){
                dfs(i,graph,disc,low,st,inStack,time,res);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};