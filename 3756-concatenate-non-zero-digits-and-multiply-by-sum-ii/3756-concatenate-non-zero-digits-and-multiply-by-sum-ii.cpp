const int mod = 1e9+7;
const int powlimit = 1e5+1;
long long power10[powlimit];
auto x = [](){
    power10[0] = 1;
    for(int i = 1;i<powlimit;i++){
        power10[i] = power10[i-1]*10 % mod;
    }
    return 0;
}();
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = s.length();
        vector<pair<int,int>> prefix(n+1);
        vector<long long> num(n+1);
        for(int i = 0;i<n;i++){
            int digit = s[i]-'0';
            prefix[i+1].first = prefix[i].first+digit;
            prefix[i+1].second = prefix[i].second + (digit>0);
            num[i+1] = (digit > 0) ? (num[i]*10+digit) % mod:num[i]; 
        }
        for(auto query:queries){
            int start = query[0];
            int end = query[1]+1;
            auto [prevsum,prevd] = prefix[start];
            auto [currsum,currd] = prefix[end];
            int len = currd-prevd;
            int val = (num[end]-num[start]*power10[len] % mod + mod) % mod;
            ans.push_back((1ll*(currsum-prevsum)*val) % mod);    
        }
        return ans;
    }
};