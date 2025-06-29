//Bubble Sort
//Time Complexity:O(n^2)
//Space Complexity:O(1)

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n=arr.size();
    for(int i=0; i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
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
        bubbleSort(arr);
        for(int x:arr) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}