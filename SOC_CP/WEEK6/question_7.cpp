class Solution {
  public:
    vector<int> candyStore(vector<int>& candies, int K) {
        // Code here
        sort(candies.begin(),candies.end());
        int mn=0,mx=0,n=candies.size(),i=0,j=n-1;
        while(i<=j){
            mn+=candies[i++];
            j-=K;
        }
        i=n-1,j=0;
        while(i>=j){
            mx+=candies[i--];
            j+=K;
        }
        return {mn,mx};
    }
};