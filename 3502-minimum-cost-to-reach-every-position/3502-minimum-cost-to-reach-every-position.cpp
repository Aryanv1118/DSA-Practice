class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int mn = INT_MAX;
        int n = cost.size();
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            mn = min(mn,cost[i]);
            ans[i] = mn;
        }
        return ans;
    }
};