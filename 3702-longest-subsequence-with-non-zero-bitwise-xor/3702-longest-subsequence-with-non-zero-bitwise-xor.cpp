class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int zc = 0;
        int total = 0;
        for(int i = 0;i<n;i++){
            total ^= nums[i];
            zc  += nums[i] == 0 ? 1:0;
        }
        if(total!=0){
            return n;
        }
        else if(zc == n){
            return 0;
        }
        else{
            return n-1;
        }
    }
};