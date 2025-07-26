class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> vis(n,false);
        vector<int> minDist(n,INT_MAX);
        minDist[0]=0;
        int cost=0;

        for(int i=0;i<n;i++){
            int u=-1,minVal=INT_MAX;
            for(int j=0;j<n;j++){
                if(!vis[j]&&minDist[j]<minVal){
                    minVal=minDist[j];
                    u=j;
                }
            }

            vis[u]=true;
            cost+=minVal;

            for(int v=0;v<n;v++){
                if(!vis[v]){
                    int d=abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                    if(d<minDist[v])minDist[v]=d;
                }
            }
        }

        return cost;
    }
};