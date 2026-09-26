class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int l  = 0;l<n;l++){
            int sum = 0;
            unordered_set<int>freq;
            for(int r = l;r<n;r++){
                sum += nums[r];
                int need = ((sum%k)+k)%k;
                int val = ((2LL*nums[r])%k + k)%k;
                freq.insert(val);
                if(need == 0 || freq.count(need))
                    ans = max(ans,r-l+1);
            }
        }
        return ans;
    }
};