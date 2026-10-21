class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string temp = s;
        sort(temp.begin(),temp.end());
        if(temp == s){
            return 0;
        }
        if(n == 2){
            if(temp!=s){
                return -1;
            }
        }
        char min_char = temp[0];
        char max_char = temp[n - 1];
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        int count = 0;
        if(s[0] == max_char && s[n-1] == min_char){
            bool mxm = false;
            bool mnm = false;
            for(int i = 1;i<n-1;i++){
                if(s[i] == min_char)mnm = true;
                if(s[i] == max_char)mxm = true;
            }
            if(!mnm && !mxm){
                return 3;
            }
        }
        return 2;
    }
};