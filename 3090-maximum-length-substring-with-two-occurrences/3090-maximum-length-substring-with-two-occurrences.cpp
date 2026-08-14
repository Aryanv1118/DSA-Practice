class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int l = 0;
        int ans = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
            while(l<i && mp[s[i]] > 2){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};