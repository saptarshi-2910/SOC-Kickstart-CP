class Solution {
  public:
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        // code here
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto&t:trains){
            int arr=t[0],dep=t[1],plt=t[2];
            mp[plt].push_back({dep,arr});
        }
        int count=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            vector<pair<int,int>>&v=it->second;
            sort(v.begin(),v.end());
            int lastDep=-1;
            for(size_t i=0;i<v.size();++i){
                int dep=v[i].first;
                int arr=v[i].second;
                if(arr>lastDep){
                    count++;
                    lastDep=dep;
                }
            }
        }
        return count;
    }
};