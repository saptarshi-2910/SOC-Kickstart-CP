 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numIndex;

        for (int i=0;i<nums.size();i++) {
            numIndex.push_back({nums[i],i});
        }
        sort(numIndex.begin(), numIndex.end());
        int left=0,right=nums.size()-1;

        while(left<right){
            int sum=numIndex[left].first+numIndex[right].first;
            if(sum==target){
                return{numIndex[left].second,numIndex[right].second};
            } else if(sum<target){
                left++;
            } else {
                right--;
            }
        }

        return{-1,-1};
    }
};
