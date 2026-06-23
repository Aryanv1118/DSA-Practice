class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0];
        int maxP = 0;
        for(int x:prices){
            minP = min(x,minP);
            maxP = max(maxP,x-minP);
        }
        return maxP;
    }
};