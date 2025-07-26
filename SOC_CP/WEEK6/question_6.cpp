// User function Template for C++
class Solution {
  public:

    int cost(vector<int>& arr) {
        // code here
        if(arr.size()<=1)return 0;
        int mn=*min_element(arr.begin(),arr.end());
        return mn*(arr.size()-1);
    }
};