//Quick Sort
//Time Complexity: O(nlogn) on average,O(n^2) worst-case
//Space Complexity: O(logn) auxiliary stack space

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr,int low,int high) {
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;++j){
        if (arr[j]<pivot){
            swap(arr[i],arr[j]);
            ++i;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}

void quickSort(vector<int>& arr,int low,int high){
    if (low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int>arr(N);
        for(int i=0;i<N;++i) cin>>arr[i];
        quickSort(arr,0,N-1);
        for (int x:arr) cout <<x<<" ";
        cout<<endl;
    }
    return 0;
}