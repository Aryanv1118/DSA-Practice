class Solution {
public:
    void backtrack(vector<string>& ans,string s,int opcount,int clcount,int n){
        if(opcount == n && clcount == n){
            ans.push_back(s);
            return;
        }
        if(opcount<n){
            backtrack(ans,s+"(",opcount+1,clcount,n);
        }
        if(clcount<opcount){
            backtrack(ans,s+")",opcount,clcount+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        backtrack(ans,s,0,0,n);
        return ans;
    }
};