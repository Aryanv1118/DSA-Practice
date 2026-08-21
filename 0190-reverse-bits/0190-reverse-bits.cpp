class Solution {
public:
    int reverseBits(int n) {
        string s = "";
        for(int i = 0;i<32;i++){
            if((n>>i) & 1){
                s += "1";
            }
            else{
                s += "0";
            }
        }
        int ans = 0;
        for(int i = 0;i<32;i++){
            ans += (s[i]-'0')*pow(2,31-i);
        }
        return ans;
    }
};