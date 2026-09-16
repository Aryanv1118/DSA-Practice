class Solution {
public:
    static const long long mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<vector<long long>>dp(n,vector<long long>(5,1));
        for(int i = 1;i<=n-1;i++){
            dp[i][0] = (dp[i-1][1])%mod;
            dp[i][1] = (dp[i-1][0]+dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][3]+dp[i-1][4])%mod;
            dp[i][3] = (dp[i-1][2]+dp[i-1][4])%mod;
            dp[i][4] = (dp[i-1][0])%mod;
        }
        int ans = (dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4])%mod;
        return ans;
    }
};