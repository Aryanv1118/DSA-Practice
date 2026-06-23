class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum = 0;
        int rsum = 0;
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
            rsum += nums[i];
        }
        for(int i = 0;i<n;i++){
            if(lsum == rsum - lsum-nums[i]){
                return i;
            }
            lsum += nums[i];
        }
        return -1;
    }
};