class Solution {
public:
    const int mod = 1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long r = 0;
        long long m = 0;
        long long ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]<a)
                ans += (m + r);
            else if(nums[i] >= a && nums[i] <= b){
                m++;
                ans += r;
            }
            else 
                r++;
        }
        return ans%mod;
    }
};