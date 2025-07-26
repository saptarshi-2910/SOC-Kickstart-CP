// User function Template for C++

class Solution {
  public:
    // Function to find the minimum number of elements in the first subset.
    int minSubset(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end(),greater<int>());
        int total=accumulate(arr.begin(),arr.end(),0),sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>total-sum)return i+1;
        }
        return arr.size();
    }
};