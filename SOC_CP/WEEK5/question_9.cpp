#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU{
  public:
    vector<int> par,rank;
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)par[i]=i;
    }
    int find(int x){
        if(par[x]!=x)par[x]=find(par[x]);
        return par[x];
    }
    bool unite(int x,int y){
        int xr=find(x),yr=find(y);
        if(xr==yr)return false;
        if(rank[xr]<rank[yr])par[xr]=yr;
        else if(rank[xr]>rank[yr])par[yr]=xr;
        else{par[yr]=xr;rank[xr]++;}
        return true;
    }
};

int minCostToConnectCities(vector<vector<int>> &edges){
    int n=0;
    for(auto &e:edges)n=max(n,max(e[0],e[1]));
    sort(edges.begin(),edges.end(),[](auto &a,auto &b){return a[2]<b[2];});
    DSU dsu(n);
    int cost=0,count=0;
    for(auto &e:edges){
        if(dsu.unite(e[0],e[1])){
            cost+=e[2];
            count++;
            if(count==n-1)break;
        }
    }
    return count==n-1?cost:-1;
}

int main(){
    vector<vector<int>> edges={{1,2,1},{1,3,2},{1,4,3},{1,5,4},{2,3,5},{2,5,7},{3,4,6}};
    cout<<minCostToConnectCities(edges)<<endl; // Output: 10
}
