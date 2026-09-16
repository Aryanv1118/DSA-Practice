class Solution {
public:
    static const long long mod = 1e9+7;
    int numberOfSets(int n, int k) {
        vector<vector<long long>>dp(k+1,vector<long long>(2,0));
        dp[0][0] = 1;
        for(int i = 1;i<n;i++){
            vector<vector<long long>>ndp = dp;
            for(int j = 0;j<=k;j++){
                ndp[j][0] = (dp[j][0]+dp[j][1])%mod;
                if(j>0){
                    ndp[j][1] = (dp[j][1]+dp[j-1][0]+dp[j-1][1])%mod;
                }
                else{
                    ndp[j][1] = 0;                
                }
            }
            dp = move(ndp);
        }
        return (dp[k][0]+dp[k][1])%mod;
    }
};