class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        vector<int> res;
        while(i<j){
            res.push_back(arr[i++]);
            res.push_back(arr[j--]);
        }
        if(arr.size()%2)res.push_back(arr[i]);
        int sum=0,n=res.size();
        for(int i=0;i<n;i++)sum+=abs(res[i]-res[(i+1)%n]);
        return sum;
    }
};