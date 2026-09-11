class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN;
        int b2 = INT_MIN;
        int s1 = 0;
        int s2 = 0;
        for(int p:prices){
            b1 = max(b1,-p);
            s1 = max(s1,b1+p);
            b2 = max(b2,s1-p);
            s2 = max(s2,b2+p);
        }
        return s2;
    }
};