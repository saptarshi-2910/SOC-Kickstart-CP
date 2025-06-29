class Solution {
  public:
    void dfs(vector<vector<int>>& image,int x,int y,int color,int newColor){
        int m=image.size(),n=image[0].size();
        if(x<0 || x>=m || y<0 || y>=n || image[x][y] != color) return;
        image[x][y]=newColor;
        dfs(image,x+1, y,color,newColor);
        dfs(image,x-1, y,color,newColor);
        dfs(image,x,y+1,color,newColor);
        dfs(image,x,y-1,color,newColor);
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
            int color=image[sr][sc];
        if (color != newColor) dfs(image,sr,sc,color,newColor);
        return image;
    }
};






