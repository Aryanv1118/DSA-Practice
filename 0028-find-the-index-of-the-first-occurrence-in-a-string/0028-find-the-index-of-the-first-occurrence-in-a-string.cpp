class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int s = haystack.size();

        if(s < n)
            return -1;

        for(int i = 0; i <= s-n; i++){
            if(haystack.substr(i,n) == needle){
                return i;
            }
        }

        return -1;
    }
};