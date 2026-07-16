class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        long long ans = 0;
        while(j<n){
            if(s[j] == s[i])
                j++;
            else{
                long long len = j-i;
                ans += (len*(len+1))/2;
                i = j;
            }
        }
        ans += ((long long)(j-i)*(j-i+1))/2;
        return (ans%mod);
    }
};