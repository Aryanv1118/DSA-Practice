class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>>dp(m,vector<vector<bool>>(n,vector<bool>(1024,false)));
        dp[0][0][grid[0][0]] = true;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0)
                    continue;
                if(i>0){
                    for(int k = 0;k<1024;k++){
                        if(dp[i-1][j][k]){
                            dp[i][j][grid[i][j]^k] = true;
                        }
                    }
                }
                if(j>0){
                    for(int k = 0;k<1024;k++){
                        if(dp[i][j-1][k]){
                            dp[i][j][grid[i][j]^k] = true;
                        }
                    }
                }
            }
        }
        for(int a = 0;a<1024;a++){
            if(dp[m-1][n-1][a])
                return a;
        }
        return 0;
    }
};