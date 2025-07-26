class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0,plat=0,maxPlat=0,n=arr.size();
        while(i<n){
            if(arr[i]<=dep[j]){
                plat++;
                maxPlat=max(maxPlat,plat);
                i++;
            }else{
                plat--;
                j++;
            }
        }   
        return maxPlat;
    }
};