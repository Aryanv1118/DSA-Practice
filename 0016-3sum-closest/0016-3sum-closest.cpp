class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int target_diff = INT_MAX;
        int ans;
        for(int i = 0;i<nums.size()-2;i++){
            int j = i+1;
            int k = nums.size()-1;
            int remaining = target - nums[i];
            while(j<k){
                if(abs(target-nums[i]-nums[j]-nums[k])<target_diff){
                    target_diff = abs(target-nums[i]-nums[j]-nums[k]);
                    ans = nums[i]+nums[j]+nums[k];
                }
                if(nums[j]+nums[k]>remaining)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};