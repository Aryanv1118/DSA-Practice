class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            prefix += nums[i];
            int avg = (prefix + i)/(i+1);
            ans = max(ans,avg);
        }
        return ans;
    }
};