class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;++i)jobs.push_back({profit[i],deadline[i]});
        sort(jobs.rbegin(),jobs.rend());
        vector<bool> slot(n+1,false);
        int cnt=0,sum=0;
            for(auto& job:jobs){
            int p=job.first,d=job.second;
            for(int i=min(n,d);i>0;--i){
                if(!slot[i]){
                    slot[i]=true;
                    ++cnt;
                    sum+=p;
                    break;
                }
            }
        }
        return {cnt,sum};
    }
};