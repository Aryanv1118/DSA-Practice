class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int mod = 1e9+7;
        set<int> divisors;
        divisors.insert(2);
        for(int x:nums){
            for(int i = 2;i*i<=x;i++){
                if(x%i == 0){
                    divisors.insert(i);
                    divisors.insert(x/i);
                }
            }
            if(x>1){
                divisors.insert(x);
            }
        }
        long long scorediff = LLONG_MIN;
        int bestk = 2;
        for(int k:divisors){
            long long currSum = 0;
            long long maxSum = LLONG_MIN;
            for(int x:nums){
                long long diff = 0;
                if(x%k == 0)
                    diff += x;
                else
                    diff -= x;
                currSum = max(diff,currSum+diff);
                maxSum = max(maxSum,currSum);
            }
            if(maxSum>scorediff || (maxSum == scorediff && k < bestk)){
                scorediff = maxSum;
                bestk = k;
            }
        }
        return (((scorediff%mod + mod)%mod)*1LL*bestk)%mod;
    }
};