class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int i = 0;
        while(i<n-1){
            int cost = prices[i+1]-prices[i];
            if(cost>0){
                profit += cost;
                i++;
            }
            else{
                i++;
                continue;
            }
        }
        return profit;
    }
};