class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>&grid,int r,int c){
        if(r == 0 && c == 0){
            return dp[r][c] = grid[0][0];
        }
        if(r<0 || c<0)
            return INT_MAX;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int left = dfs(grid,r,c-1);
        int up = dfs(grid,r-1,c);
        return dp[r][c] = grid[r][c] + min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return dfs(grid,m-1,n-1);
    }
};