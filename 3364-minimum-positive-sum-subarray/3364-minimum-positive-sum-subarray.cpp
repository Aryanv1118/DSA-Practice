class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int len = l;len<=r;len++){
            int sum = 0;
            for(int i = 0;i<n;i++){
                if(i>=len){
                    if(sum>0){
                        ans = min(ans,sum);
                    }
                    sum -= nums[i-len];
                }
                sum += nums[i];
            }
            if(sum>0){
                ans = min(ans,sum);
            }
        }
        return ans == INT_MAX ?-1:ans;
    }
};