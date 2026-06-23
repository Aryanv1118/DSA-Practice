class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector<int> freq (26,0);
        int max_len = 0;
        while(r<n){
            freq[s[r]-'A']++;
            int max_freq = *max_element(freq.begin(),freq.end());
            while(r-l+1-max_freq >k){
                freq[s[l]-'A']--;
                l++;
            }
            max_len = max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};