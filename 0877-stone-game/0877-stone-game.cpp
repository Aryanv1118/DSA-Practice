class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        for(int x:piles){
            total ^= x;
        }
        return total%2 == 1;
    }
};