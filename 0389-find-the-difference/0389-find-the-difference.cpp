class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        int n = s.length();
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
        }
        char ans;
        for(int i = 0;i<=n;i++){
            mp[t[i]]--;
            if(mp[t[i]]<0){
                ans = t[i];
                break;
            }
        }
        return ans;
    }
};