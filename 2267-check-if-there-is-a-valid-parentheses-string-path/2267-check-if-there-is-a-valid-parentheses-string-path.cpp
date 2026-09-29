class Solution {
public:
    int m,n;
    int dp[105][105][205];
    bool dfs(vector<vector<char>>&grid,int balance,int r,int c){
        if(r >= m || c >= n || balance<0){
            return false;
        }
        if(grid[r][c] == '('){
            balance++;
        }
        else{
            balance--;
        }
        if(balance<0){
            return false;
        }
        if(balance > (m-1-r)+(n-1-c))   
            return false;
        if(r == m-1 && c == n-1)
            return balance == 0;
        if(dp[r][c][balance]!=-1){
            return dp[r][c][balance];
        }
        bool path = dfs(grid,balance,r+1,c) || dfs(grid,balance,r,c+1);
        return dp[r][c][balance] = path;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if((m+n-1)%2 != 0)return false;
        memset(dp,-1,sizeof(dp));
        return dfs(grid,0,0,0);
    }
};