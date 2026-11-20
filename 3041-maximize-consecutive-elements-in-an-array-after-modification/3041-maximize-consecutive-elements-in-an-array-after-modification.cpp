class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        vector<int>dp(1000002,0);
        int ans  = 0;
        sort(nums.begin(),nums.end());
        for(int x:nums){
            dp[x+1] = dp[x]+1;
            dp[x] = dp[x-1]+1;
            ans = max({ans,dp[x],dp[x+1]});
        }
        return ans;
    }
};