class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefix = 0;
        int maxheight = INT_MIN;
        for(int x:gain){
            maxheight = max(maxheight,prefix);
            prefix += x;
        }
        maxheight = max(maxheight,prefix);
        return maxheight;
    }
};