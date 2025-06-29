//Merge Sort
//Time Complexity:O(nlogn)
//Space Complexity:O(n)

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int left,int mid,int right){
    vector<int> temp(right-left+1);
    int i=left,j=mid+1,k=0;
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];
    for(int p=0;p<temp.size();++p) arr[left+p]=temp[p];
}

void mergeSort(vector<int>& arr,int left,int right){
    if (left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i=0; i<N;++i) cin>>arr[i];
        mergeSort(arr,0,N-1);
        for (int x:arr) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}