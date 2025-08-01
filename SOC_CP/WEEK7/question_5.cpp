class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n=triangle.size();
        vector<int> dp=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++)
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
        }
        return dp[0];
    }
};