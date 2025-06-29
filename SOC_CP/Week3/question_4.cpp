#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin>>n;

    map<int,int> height;

    for(int i=0;i<n;++i){
        int left,right,h;
        cin>>left>>right>>h;

        for(int x=left;x<right;++x){
            height[x]=max(height[x],h);
        }
    }

    int area=0;
    for(auto& p:height){
        area+=p.second;
    }

    cout<<area<<endl;
    return 0;
}
