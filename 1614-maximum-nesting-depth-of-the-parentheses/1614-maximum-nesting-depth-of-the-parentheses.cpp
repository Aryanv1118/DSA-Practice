class Solution {
public:
    int maxDepth(string s) {
        int op = 0;
        int ans = 0;
        for(char c:s){
            if(c == '('){
                op++;
            }
            else if(c == ')'){
                op--;
            }
            ans = max(ans,op);
        }
        return ans;
    }
};