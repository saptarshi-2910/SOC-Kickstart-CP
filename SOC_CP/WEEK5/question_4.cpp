// User function Template for C++
class Solution {
  public:
    int find(int u,vector<int> &parent){
        if(parent[u]!=u)parent[u]=find(parent[u],parent);
        return parent[u];
    }

    void unite(int u,int v,vector<int> &parent,vector<int> &rank){
        u=find(u,parent);
        v=find(v,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }else if(rank[v]<rank[u]){
            parent[v]=u;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int> &b){
            return a[2]<b[2];
        });

        vector<int> parent(V),rank(V,0);
        for(int i=0;i<V;i++)parent[i]=i;

        int mstWeight=0;
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(find(u,parent)!=find(v,parent)){
                unite(u,v,parent,rank);
                mstWeight+=w;
            }
        }

        return mstWeight;
    }
};