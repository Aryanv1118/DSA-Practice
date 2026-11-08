class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dr[4] = {1,0,0,-1};
        int dc[4] = {0,1,-1,0};
        vector<int>rows(m,0);
        vector<int>cols(n,0);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] && (rows[i]>1 || cols[j]>1))
                    ans++;
            }
        }
        return ans;
    }
};