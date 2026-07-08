class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long winsum = 0;
        int ans = 0;
        for(r = 0;r<n;r++){
            winsum += nums[r];
            while((long long)(r-l+1)*nums[r]-winsum>k){
                winsum -= nums[l];
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};