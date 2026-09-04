class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx(n);
        vector<int> mn(n);
        int m_x = INT_MIN;
        for (int i = 0; i < n; i++) {
            m_x = max(m_x, nums[i]);
            mx[i] = m_x;
        }
        int m_n = INT_MAX;
        for (int j = n - 1; j >= 0; j--) {
            m_n = min(m_n, nums[j]);
            mn[j] = m_n;
        }
        for(int i = 0;i<n;i++){
            int instabilityScore = mx[i] - mn[i];
            if (instabilityScore <= k) {
                return i;
            }
        }
        return -1;
    }
};