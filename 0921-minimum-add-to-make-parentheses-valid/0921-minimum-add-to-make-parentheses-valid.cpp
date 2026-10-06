class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int op = 0;
        for(char c:s){
            if(op<0){
                op++;
                ans++;
            }
            if(c == '('){
                op++;
            }
            else{
                op--;
            }
        }
        if(op!=0){
            ans += abs(op);
        }
        return ans;
    }
};