class Solution {
public:
    vector<int>dp;
    int dfs(int x,int y){
        if(x <= y){
            return y-x;
        }
        if(dp[x]!= -1)
            return dp[x];
        int ans = abs(x-y);
        ans = min(ans, x % 5 + 1 + dfs(x / 5, y));
        ans = min(ans, (5 - x % 5) + 1 + dfs(x / 5 + 1, y));
        ans = min(ans, x % 11+ 1 + dfs(x / 11, y));
        ans = min(ans, (11 - x % 11) + 1 + dfs(x / 11 + 1, y));
        return dp[x] = ans;  
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        dp.assign(x+1,-1);
        return dfs(x,y);  
    }
};