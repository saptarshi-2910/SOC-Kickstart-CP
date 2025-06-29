class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxsum=nums[0];

        for (int i=0;i<nums.size();i++){
            int currentsum=0;         
            for (int j=i;j<nums.size();j++){
                currentsum=currentsum+nums[j];
                maxsum= max(currentsum,maxsum);
            }

        }
      
        return maxsum;
    }
};