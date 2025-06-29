// User function Template for C++

class Solution {
  public:
    int minThrow(int N, int arr[]) {
        // code here
        vector<int> board(31,0);
        for(int i=0;i<2*N;i+=2){
            board[arr[i]]=arr[i+1];
        }

        vector<bool> vis(31,false);
        queue<pair<int,int>> q;
        q.push({1,0});
        vis[1]=true;

        while(!q.empty()){
            int curr=q.front().first;
            int dist=q.front().second;
            q.pop();

            if(curr==30) return dist;

            for(int dice=1;dice<=6;dice++){
                int next=curr+dice;
                if(next>30) continue;
                if(board[next]!=0) next=board[next];
                if(!vis[next]){
                    vis[next]=true;
                    q.push({next,dist+1});
                }
            }
        }

        return -1;
    }
};
