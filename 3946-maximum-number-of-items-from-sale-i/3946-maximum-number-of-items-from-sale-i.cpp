class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAX_F = 1500;
        vector<int> freq(MAX_F + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        vector<int> divCount(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; ++f) {
            if (freq[f] == 0) continue;
            for (int mult = f; mult <= MAX_F; mult += f) {
                divCount[f] += freq[mult];
            }
        }
        vector<int> dp(budget + 1, 0);
        for (const auto& item : items) {
            int f = item[0], p = item[1];
            int val = divCount[f];
            for (int b = budget; b >= p; --b) {
                dp[b] = max(dp[b], dp[b - p] + val);
            }
        }
        for (const auto& item : items) {
            int p = item[1];
            for (int b = p; b <= budget; ++b) {
                dp[b] = max(dp[b], dp[b - p] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};