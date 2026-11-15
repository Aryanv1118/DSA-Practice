class Solution {
public:
    static const int mod = 1e9+7;
    int numOfSubarrays(vector<int>& nums) {
        long long even = 1;
        long long odd = 0;
        long long ans = 0;
        long long pref = 0;
        for(int x:nums){
            pref += x;
            if(pref %2 == 0){
                ans += odd;
                even++;
            }
            else{
                ans += even;
                odd++;
            }
        }
        return ans%mod;
    }
};