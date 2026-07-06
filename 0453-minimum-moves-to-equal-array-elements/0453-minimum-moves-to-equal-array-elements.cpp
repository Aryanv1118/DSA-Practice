class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minimum = *min_element(nums.begin(),nums.end());
        for(auto x:nums){
            sum += x-minimum;
        }
        return sum;
    }
};