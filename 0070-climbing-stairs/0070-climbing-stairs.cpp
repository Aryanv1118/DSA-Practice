class Solution {
public:
    vector<int> dp;
    int dfs(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int sum = dfs(n-1)+dfs(n-2);
        dp[n] = sum;
        return sum;
    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return dfs(n);
    }
};