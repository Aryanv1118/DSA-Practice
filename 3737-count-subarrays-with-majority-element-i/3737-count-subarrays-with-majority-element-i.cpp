class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int prefix = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            prefix = 0;
            for(int j = i;j<n;j++){
                if(nums[j] == target){
                    prefix++;
                }
                else{
                    prefix--;
                }
                if(prefix > 0)
                    ans++;
            }
        }
        return ans;
    }
};