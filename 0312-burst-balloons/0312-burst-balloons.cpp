class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<int>&nums,int l,int r){
        if(dp[l][r]!=-1)
            return dp[l][r];
        if(l>r){
            return dp[l][r] = 0;
        }
        if(l == r)
            return dp[l][r] = nums[l-1]*nums[l]*nums[l+1];
        int ans = 0;
        for(int i = l;i<=r;i++){
            ans = max(ans,dfs(nums,l,i-1)+dfs(nums,i+1,r)+nums[l-1]*nums[i]*nums[r+1]);
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        dp.assign(n,vector<int>(n,-1));
        return dfs(nums,1,n-2);
    }
};