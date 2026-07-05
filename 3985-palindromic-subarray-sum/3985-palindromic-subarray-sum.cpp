class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        long long ans = 0;
        vector<int> d1(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && nums[i - k] == nums[i + k])
                k++;
            d1[i] = k;
            int left = i - k + 1;
            int right = i + k - 1;
            ans = max(ans, prefix[right + 1] - prefix[left]);
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        vector<int> d2(n);
        l = 0;
        r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n &&nums[i - k - 1] == nums[i + k])
                k++;
            d2[i] = k;
            if (k > 0) {
                int left = i - k;
                int right = i + k - 1;
                ans = max(ans, prefix[right + 1] - prefix[left]);
            }
            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }
        return ans;
    }
};