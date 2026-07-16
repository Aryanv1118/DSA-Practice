class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int mx = 0;
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
            int val = gcd(nums[i],mx);
            prefix[i] = val;
        }
        long long ans = 0;
        int k = 0;
        int j = n-1;
        sort(prefix.begin(),prefix.end());
        while(k<j){
            ans += gcd(prefix[k],prefix[j]);
            k++;
            j--;
        }
        return ans;
    }
};