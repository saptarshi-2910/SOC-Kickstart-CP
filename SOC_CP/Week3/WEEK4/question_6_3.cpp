class Solution {
public:
        bool dfs(int x,int y,int px,int py,vector<vector<char>>& grid,vector<vector<bool>>& vis,int m,int n){
        vis[x][y]=true;
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto [dx,dy]:dir){
            int nx=x+dx,ny=y+dy;
            if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
            if(grid[nx][ny] != grid[x][y]) continue;
            if(!vis[nx][ny]){
                if(dfs(nx,ny,x,y,grid,vis,m,n)) return true;
            }else if(nx != px || ny != py){
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis,m,n)) return true;
                }
            }
        }
        return false;
    }
};