class Solution {
public:
    static const int mod = 1000000007;
    vector<long long>vis;
    vector<long long>dp;
    long long dfs(string& s,int i){
        if(i < 0){
           return 1; 
        }
        if(dp[i]!= -1)
            return dp[i];
        long long old = dfs(s,i-1); 
        dp[i] = (2*old-vis[s[i]-'a'])%mod;
        if(dp[i]<0)dp[i]+=mod;
        vis[s[i]-'a'] = old;
        return dp[i];  
    }
    long long distinctSubseqII(string s) {
        vis.assign(26,0);
        dp.assign(s.length(),-1);
        return (dfs(s,s.length()-1)-1+mod)%mod;
    }
};