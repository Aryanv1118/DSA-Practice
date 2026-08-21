class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int k = n-1;
        while(k >= 0 && s[k] == ' '){
            k--;
        }
        int len = 0;
        while(k >=0 && s[k] != ' '){
            k--;
            len++;
        }
        return len;
    }
};