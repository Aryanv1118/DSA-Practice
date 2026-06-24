class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int n = cost.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            if((i+1)%3 == 0)
                continue;
            ans += cost[i];
        }
        return ans;
    }
};