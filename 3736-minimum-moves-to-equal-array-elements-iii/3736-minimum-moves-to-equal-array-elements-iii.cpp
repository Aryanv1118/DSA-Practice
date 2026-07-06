class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int maximum = *max_element(nums.begin(),nums.end());
        for(auto x:nums){
            sum += maximum - x;
        }
        return sum;
    }
};