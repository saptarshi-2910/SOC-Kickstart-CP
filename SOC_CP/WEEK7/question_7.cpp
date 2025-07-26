class Solution {
public:
    int robLinear(vector<int>& nums,int l,int r) {
        int prev=0,curr=0;
        for(int i=l;i<=r;i++) {
            int pick=nums[i]+prev;
            int notPick=curr;
            int temp=max(pick,notPick);
            prev=curr;
            curr=temp;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(robLinear(nums,0,n-2),robLinear(nums,1,n-1));
    }
};