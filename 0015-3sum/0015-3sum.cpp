class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            int j = i+1;
            int k = n-1;
            if(nums[i] > 0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            while(j<k){
                int target = -nums[i];
                if(nums[j]+nums[k] == target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
                else if(nums[j]+nums[k]<target){
                    j++;
                }
                else
                    k--;
            }
        }
        return ans;
    }
};