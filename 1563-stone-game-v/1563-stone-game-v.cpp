class Solution {
public:
    vector<vector<int>>dp;
    long long dfs(vector<int>&nums,int l,int r){
        if(l + 1>= r){
            return 0;
        }
        if(dp[l][r] != 0){
            return dp[l][r];
        }
        long long ans = 0;
        for(int i = l+1;i<r;i++){
            int leftsum = nums[i]-nums[l];
            int rightsum = nums[r] - nums[i];   
            if(leftsum < rightsum){
                ans = max(ans,leftsum + dfs(nums,l,i));
            }
            else if(rightsum < leftsum){
                ans = max(ans,rightsum + dfs(nums,i,r));
            }
            else{
                ans = max(ans ,max(leftsum + dfs(nums,l,i),rightsum + dfs(nums,i,r)));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1,vector<int>(n+1,0));
        vector<int>prefix(n+1);
        for(int i = 0;i<n;i++){
            prefix[i+1] = prefix[i] + stoneValue[i];
        }
        dfs(prefix,0,n);
        return dp[0][n];
    }
};