class Solution {
public:
    vector<vector<int>>dp;
    int dfs(string&s,string&t,int i,int j){
        if(j == t.length())return 1;
        if(i == s.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i] == t[j])
            dp[i][j] = dfs(s,t,i+1,j+1)+dfs(s,t,i+1,j);
        else
            dp[i][j] = dfs(s,t,i+1,j);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        dp.assign(ns,vector<int>(nt,-1));
        return dfs(s,t,0,0);
    }
};