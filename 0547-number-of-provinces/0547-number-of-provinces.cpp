class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjList(n);
        vector<bool>vis(n,false);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] && i!=j)
                    adjList[i].push_back(j);
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                queue<int>q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int idx = q.front();
                    q.pop();
                    for(int neigh:adjList[idx]){
                        if(!vis[neigh]){
                            q.push(neigh);
                            vis[neigh] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};