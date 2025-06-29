//Selection Sort
//Time Complexity:O(n^2)
//Space Complexity:O(1)

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n-1;++i){
        int minIndex=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
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
        selectionSort(arr);
        for(int x:arr) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}