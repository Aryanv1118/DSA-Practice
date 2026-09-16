class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        string ans(n,' ');
        for(int i = 0;i<s.length();i++){
            ans[indices[i]] = s[i];
        }
        return ans;

    }
};