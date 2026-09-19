class Solution {
public:
    bool checkString(string s) {
        int ac = 0;
        int bc = 0;
        int n = s.length();
        bool ans = true;
        for(int i = 0;i<n;i++){
            if(s[i] == 'a'){
                ac++;
                if(bc>0){
                    ans = false;
                }
            }
            else{
                bc++;
            }
        }
        return ans;
    }
};