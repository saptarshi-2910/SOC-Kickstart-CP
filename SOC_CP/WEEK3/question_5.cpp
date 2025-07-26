class Solution {
  public:
    bool isValid(vector<int> &arr,int k,int maxPages) {
        int students=1;
        int pages=0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxPages) return false;

            if(pages+arr[i]>maxPages){
                students++;
                pages=arr[i];
            } else{
                pages+=arr[i];
            }
        }
        return students<=k;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        if (k>arr.size()) return -1;

        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int result=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(isValid(arr,k,mid)){
                result=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }

        return result;
    }
};
 
