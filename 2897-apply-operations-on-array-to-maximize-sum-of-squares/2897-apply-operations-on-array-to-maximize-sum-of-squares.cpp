class Solution {
public:
    const int mod = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        for(int x:nums){
            for(int b = 0;b<31;b++){
                if(x&1<<b){
                    bits[b]++;
                }
            }
        }
        long long ans = 0;
        while(k--){
            long long x = 0;
            for(int i = 0;i<31;i++){
                if(bits[i]>0){
                    x |= 1<<i;
                    bits[i]--;
                }
            }
            ans = (ans + x*x)%mod;
        }
        return ans;
    }
};