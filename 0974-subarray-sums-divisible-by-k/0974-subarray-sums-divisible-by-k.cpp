class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int rem;
        int prefix = 0;
        int ans = 0;
        mp[0] = 1;
        for(int x:nums){
            prefix += x;
            rem = ((prefix % k)+k) % k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};