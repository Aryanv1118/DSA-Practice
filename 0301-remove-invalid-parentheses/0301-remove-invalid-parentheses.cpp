class Solution {
public:
    set<string>ans;
    int maxOpen = 0;
    void backtrack(int idx,int open,int close,string current,string &s,int remOpen,int remclose){
        if(idx == s.length()) {
            if(remOpen == 0 && remclose == 0)
                ans.insert(current);
            return;
        }
        if(s[idx] == '('){
            backtrack(idx+1,open+1,close, current+"(",s,remOpen,remclose);
            if(remOpen>0){
                backtrack(idx+1,open,close,current,s,remOpen-1,remclose);
            }
        }
        else if(s[idx] == ')'){
            if(close<open){
                backtrack(idx+1,open,close+1, current+")",s,remOpen,remclose);
            }
            if(remclose>0){
                backtrack(idx+1,open,close,current,s,remOpen,remclose-1);
            }
        }
        else{
            backtrack(idx+1,open,close, current+s[idx],s,remOpen,remclose);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string curr = "";
        int n = s.length();
        int rmop = 0;
        int remOpen = 0;    
        int remClose = 0;
        for(char c : s) {
            if(c == '(') {
                remOpen++;
            }
            else if(c == ')') {
                if(remOpen > 0)
                    remOpen--;
                else
                    remClose++;
            }
        }
        backtrack(0,0,0,curr,s,remOpen,remClose);
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};