class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int n = r+1;
        int k = n-1;
        vector<int> ans(n);
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                ans[k] = nums[l]*nums[l];
                l++;
                k--;
            }
            else{
                ans[k] = nums[r]*nums[r];
                r--;
                k--;
            }
            
        }
        return ans;
    }
};