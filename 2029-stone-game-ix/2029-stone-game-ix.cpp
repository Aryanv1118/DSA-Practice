class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for(int i = 0;i<n;i++){
            if(stones[i]%3 == 0)zeros++;
            else if(stones[i]%3 == 1)ones++;
            else twos++;
        }
        if(zeros % 2 == 0) return ones > 0 && twos > 0;
        else return abs(ones-twos)>2;
    }
};