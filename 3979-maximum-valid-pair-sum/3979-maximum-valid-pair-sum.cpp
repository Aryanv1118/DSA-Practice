class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int first = nums[0];
        int ans = INT_MIN;
        for(int j = k;j<n;j++){
            first = max(first,nums[j-k]);
            ans = max(ans,first+nums[j]);
        }
        return ans;
    }
};