class Solution {
public:
    static const int mod = 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        vector<vector<int>>left(m,vector<int>(n,0));
        vector<vector<int>>up(m,vector<int>(n,0));
        dp[0][0] = 1;
        if (m > 1)
            up[1][0] = 1;
        if (n > 1)
            left[0][1] = 1;;
        for(int r = 0;r<m;r++){
            for(int c = 0;c<n;c++){
                if (r == 0 && c == 0) continue;
                if (grid[r][c] == 1) {
                    if (r + 1 < m)
                        up[r+1][c] = (up[r+1][c] + left[r][c]) % mod;
                    if (c + 1 < n)
                        left[r][c+1] = (left[r][c+1] + up[r][c]) % mod;
                }
                else {
                    dp[r][c] = (left[r][c] + up[r][c]) % mod;
                    if (r + 1 < m)
                        up[r+1][c] = (up[r+1][c] + dp[r][c]) % mod;
                    if (c + 1 < n)
                        left[r][c+1] = (left[r][c+1] + dp[r][c]) % mod;
                }
            }
        }
        return dp[m-1][n-1];
    }
};