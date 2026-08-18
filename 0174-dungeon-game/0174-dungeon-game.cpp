class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>&nums,int i,int j){
        int n = nums.size();
        int m = nums[0].size();
        if(i>=n || j >= m){
            return INT_MAX;
        }
        if (i == n - 1 && j == m - 1) {
            return max(1, 1 - nums[i][j]);
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int next_hp = min(dfs(nums,i+1,j),dfs(nums,i,j+1));
        return dp[i][j] = max(1,next_hp-nums[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        dp.assign(n,vector<int>(m,INT_MAX));
        return dfs(dungeon,0,0);
    }
};