class Solution {
public:
    vector<int>dp;
    vector<int>squares;
    bool dfs(int n){
        if(n == 0)
            return false;
        if(dp[n]!=-1)
            return dp[n];
        for(auto &sq:squares){
            if(sq>n){
                break;
            }
            if(!dfs(n-sq))
                return dp[n] = 1;
        }
        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        for(int i = 1;i*i<=n;i++){
            squares.push_back(i*i);
        }
        return dfs(n);
    }
};