class Solution {
    using ll = long long;
    multiset<int> left, right;
    ll sumLeft = 0, sumRight = 0;
    void add(int x) {
        if (left.empty() || x <= *left.rbegin()) {
            left.insert(x);
            sumLeft += x;
        } else {
            right.insert(x);
            sumRight += x;
        }
        balance();
    }
    void remove(int x) {
        auto it = left.find(x);
        if (it != left.end()) {
            sumLeft -= x;
            left.erase(it);
        } else {
            it = right.find(x);
            sumRight -= x;
            right.erase(it);
        }
        balance();
    }
    void balance() {
        while (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            int x = *it;
            left.erase(it);
            sumLeft -= x;
            right.insert(x);
            sumRight += x;
        }
        while (left.size() < right.size()) {
            auto it = right.begin();
            int x = *it;
            right.erase(it);
            sumRight -= x;
            left.insert(x);
            sumLeft += x;
        }
    }
    ll getCost() {
        ll median = *left.rbegin();
        return median * (ll)left.size() - sumLeft + sumRight - median * (ll)right.size();
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<ll> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x)
                remove(nums[i - x]);
            if (i >= x - 1)
                cost[i - x + 1] = getCost();
        }
        const ll INF = LLONG_MAX / 4;
        vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, INF));
        dp[0][0] = 0;

        for (int j = 0; j <= k; j++) {
            for (int i = 0; i <= n; i++) {
                if (dp[j][i] == INF) continue;
                if (i < n) {
                    dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);
                }
                if (j < k && i + x <= n) {
                    dp[j + 1][i + x] = min(dp[j + 1][i + x], dp[j][i] + cost[i]);
                }
            }
        }

        return *min_element(dp[k].begin(),dp[k].end());
    }
};
