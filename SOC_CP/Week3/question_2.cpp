class Solution {
  public:

    long long mergeAndCount(vector<int> &arr,int left,int mid,int right) {
        vector<int> leftSub(arr.begin()+left, arr.begin()+mid+1);
        vector<int> rightSub(arr.begin()+mid+1,arr.begin()+right+1);
        
        int i=0,j=0,k=left;
        long long invCount=0;
        
        while(i<leftSub.size() && j<rightSub.size()) {
            if(leftSub[i]<=rightSub[j]) {
                arr[k++]=leftSub[i++];
            } else{
                arr[k++]=rightSub[j++];
                invCount+=(leftSub.size()-i);
            }
        }
        
        while (i<leftSub.size()) arr[k++]=leftSub[i++];
        while (j<rightSub.size()) arr[k++]=rightSub[j++];
        
        return invCount;
    }
    
    long long mergeSortAndCount(vector<int> &arr,int left,int right) {
        long long invCount=0;
        if(left<right){
            int mid=left+(right-left)/2;
            invCount+=mergeSortAndCount(arr,left,mid);
            invCount+=mergeSortAndCount(arr,mid+1,right);
            invCount+=mergeAndCount(arr,left,mid,right);
        }
        return invCount;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr){
        // Your Code Here
        return (int)mergeSortAndCount(arr,0,arr.size()-1);
    }
};







