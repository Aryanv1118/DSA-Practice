class Solution {
public:
    vector<vector<int>>dp;
    bool dfs(string &s1,string &s2,string &s3,int i,int j){
        bool op1 = false;
        bool op2 = false;
        if(dp[i][j]!=-1)
            return  dp[i][j];
        if(i+j == s3.size())
            return true;
        if(i<s1.size() && s1[i] == s3[i+j])
            op1 = dfs(s1,s2,s3,i+1,j);
        if(j<s2.size() && s2[j] == s3[i+j])
            op2 = dfs(s1,s2,s3,i,j+1);
        return dp[i][j] = op1 || op2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        if(s1.size()+s2.size() != s3.size())
            return false;
        return dfs(s1,s2,s3,0,0);
    }
};