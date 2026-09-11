class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];
        int ans = nums[0];
        for(int i = 1;i<nums.size();i++){
            int mn = min_prod;
            min_prod = min({nums[i],min_prod*nums[i],max_prod*nums[i]});
            max_prod = max({nums[i],max_prod*nums[i],mn*nums[i]});
            ans = max(ans,max_prod);
        }
        return ans;
    }
};