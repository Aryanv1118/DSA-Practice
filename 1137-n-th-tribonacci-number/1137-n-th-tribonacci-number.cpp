class Solution {
public:
    vector<int> dp;
    int dfs(int n){
        if(n <= 1)
            return n;
        if(n == 2)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int sum = dfs(n-3)+dfs(n-2)+dfs(n-1);
        dp[n] = sum;
        return dp[n];
    }
    int tribonacci(int n) {
        dp.assign(n+1,-1);
        return dfs(n);
    }
};