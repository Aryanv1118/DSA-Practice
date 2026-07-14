const int mod = 1e9+7;
class Solution {
public:
    vector<int> powersvector(int n){
        vector<int> powers;
        for(int i = 0;i<31;i++){
            if(n & (1<<i)){
                powers.push_back(1ll<<i);
            }
        }
        return powers;
    }
    long long modPow(long long base, long long exp){
        long long ans = 1;
        while(exp){
            if(exp & 1)
                ans = (ans * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return ans;
    }
    long long modInverse(long long x){
        return modPow(x, mod - 2);
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers = powersvector(n);
        int s = powers.size();
        vector<long long>prefix(s+1);
        prefix[0] = 1;
        for(int i = 0;i<s;i++){
            prefix[i+1] = (prefix[i]*powers[i])%mod;
        }
        vector<int> ans;
        for(auto query:queries){
            int l = query[0];
            int r = query[1];
            long long val = prefix[r + 1];
            val = (val * modInverse(prefix[l])) % mod;
            ans.push_back(val%mod);
        }
        return ans;
    }
};