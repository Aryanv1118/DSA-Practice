class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& nums,int idx,int row){
        if(row == nums.size())
            return 0;
        if(dp[row][idx]!=INT_MAX){
            return dp[row][idx];
        }
        int left = dfs(nums,idx,row+1);
        int right = dfs(nums,idx+1,row+1);
        return dp[row][idx] = nums[row][idx] + min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n,vector<int>(n,INT_MAX));
        return dfs(triangle,0,0);
    }
};