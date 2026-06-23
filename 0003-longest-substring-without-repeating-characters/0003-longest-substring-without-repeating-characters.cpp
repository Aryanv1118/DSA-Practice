class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxs = 0;
        while(r<n){
            while(set.count(s[r])){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            int size = r-l+1;
            maxs = max(maxs,size);
            r++;
        }
        return maxs;
    }
};