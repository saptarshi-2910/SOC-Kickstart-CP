#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> intervals(n);

    for(int i=0;i<n;++i){
        cin>>intervals[i].first>>intervals[i].second;
    }

    sort(intervals.begin(),intervals.end());

    int totalLength=0;
    int currentStart=intervals[0].first;
    int currentEnd=intervals[0].second;

    for(int i=1;i<n;++i){
        int nextStart=intervals[i].first;
        int nextEnd=intervals[i].second;

        if(nextStart<=currentEnd){
            currentEnd=max(currentEnd,nextEnd);
        } else{
            totalLength+=currentEnd-currentStart;
            currentStart=nextStart;
            currentEnd=nextEnd;
        }
    }
    totalLength+=currentEnd-currentStart;

    cout<<totalLength<<endl;
    return 0;
}
