class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int ab = 0;
        int idx;
        int decr = 0;
        if(n <= 2)
            return true;
        for(int i = 1;i<n;i++){
            if(nums[i-1]>=nums[i]){
               ab++;
               idx = i-1;
            }
        }
        if(ab > 1)
            return false;
        if(ab == 0)
            return true;
        if(ab == 1){
            bool rp = (idx == 0) || (nums[idx-1]<nums[idx+1]);
            bool rm = (idx+1 == n-1) || (nums[idx]<nums[idx+2]);
            return rp||rm;
        }
        return false;
    }
};