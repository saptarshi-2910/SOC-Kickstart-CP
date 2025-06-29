class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int m=mat.size();
        int n=mat[0].size();
        int time=0;
        int fresh=0;
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 2) q.push({i,j});
                else if(mat[i][j] == 1) fresh++;
            }
        }

        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty() && fresh>0){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                    int nx=x+dir[d][0];
                    int ny=y+dir[d][1];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || mat[nx][ny] != 1) continue;
                    mat[nx][ny]=2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
            time++;
        }

        return fresh==0?time:-1;
    }
};