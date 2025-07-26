class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        for(auto& interval:arr){
            if(res.empty()||res.back()[1]<interval[0])res.push_back(interval);
            else res.back()[1]=max(res.back()[1],interval[1]);
        }
        return res;
    }
};