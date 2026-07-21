class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1;j<n-2;j++){
                long long req = (long long)target - (nums[i] +nums[j]);
                int k = j+1;
                int l = n-1;
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                while(k<l){
                    long long sum = nums[l]+nums[k];
                    if(sum == req){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1])
                            k++;
                        while(k<l && nums[l] == nums[l+1])
                            l--;
                    }
                    else if(sum<req)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
};