class Solution {
public:
    const long long mod = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        for(auto x: nums){
            sum += x;
        }
        if(k >= sum){
            return 0;
        }
        long long opp = 0;
        long long avlresources = k;
        long long totalcost = 0;
        for(auto x:nums){
            if(avlresources < x){
                long long req = (1ll*x-avlresources+k-1)/k;
                long long start = opp+1;
                long long end = opp + req;
                __int128 sum = (__int128)req*(start+end)/2;
                totalcost = (totalcost+(long long)(sum%mod))%mod;
                opp += req;
                avlresources += (__int128)req*k;
            }
            avlresources -= x;
        }
        return (totalcost%mod);
    }
};