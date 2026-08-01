class Solution {
public:
    int dfs(vector<int>&nums, int l,int r){
        if(l == r)
            return nums[l];
        int left = nums[l]-dfs(nums,l+1,r);
        int right = nums[r] - dfs(nums,l,r-1);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums){
        int n = nums.size()-1;
        return dfs(nums,0,n)>=0;
    }
};