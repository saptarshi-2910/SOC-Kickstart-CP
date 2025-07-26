class Solution{
  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid){
        int n=grid.size();
        if(grid[0][0]!=0||grid[n-1][n-1]!=0)return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;

        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

        while(!q.empty()){
            auto [x,y]=q.front();
            int d=grid[x][y];
            q.pop();
            if(x==n-1&&y==n-1)return d;

            for(auto &p:dir){
                int i=x+p.first,j=y+p.second;
                if(i>=0&&j>=0&&i<n&&j<n&&grid[i][j]==0){
                    q.push({i,j});
                    grid[i][j]=d+1;
                }
            }
        }

        return -1;
    }
};
