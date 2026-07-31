class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(int i = 0;i<word.length();i++){
            freq[word[i]-'a']++;
        }
        int ans = 0;
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
        for(int i = 0;i<26;i++){
            int pushes = i/8+1;
            ans += pushes*freq[i];
        }
        return ans;
    }
};