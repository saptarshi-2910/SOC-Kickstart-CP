//Insertion Sort
//Time Complexity:O(n^2)
//Space Complexity:O(1)

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
    int n=arr.size();
    for(int i=1;i<n;++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i=0;i<N;++i) cin>>arr[i];
        insertionSort(arr);
        for(int x:arr) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}