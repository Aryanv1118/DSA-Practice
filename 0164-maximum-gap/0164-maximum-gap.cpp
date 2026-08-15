class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1)
            return 0;
        int ans = INT_MIN;
        for(int i = 1;i<n;i++){
            ans = max(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};