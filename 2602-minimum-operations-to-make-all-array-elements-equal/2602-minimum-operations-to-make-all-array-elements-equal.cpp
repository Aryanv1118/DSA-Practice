class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<long long>prefix(n+1);
        for(int i = 0;i<n;i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        vector<long long> ans;
        for(auto &q:queries){
            auto it = lower_bound(nums.begin(),nums.end(),q);
            long long temp = 0;
            int idx = distance(nums.begin(),it);
            temp += (1LL*idx*q - prefix[idx]);
            temp += ((prefix[n]-prefix[idx]) - 1LL*(n-idx)*q);
            ans.push_back(temp);
        }
        return ans;
    }
};