class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> ans;
        set<string> cur = join(s, i);
        for (string x : cur)
            ans.insert(x);
        while (i < s.size() && s[i] == ',') {
            i++;
            cur = join(s, i);
            for (string x : cur)
                ans.insert(x);
        }
        return ans;
    }
    set<string> join(string &s,int &i){
        set<string>ans = {""};
        while(i<s.size() && s[i]!=','&&s[i]!='}'){
            set<string>curr = part(s,i);
            set<string>temp;
            for(string x:ans){
                for(string y:curr){
                    temp.insert(x+y);
                }
            }
            ans = temp;
        }
        return ans;
    }
    set<string> part(string &s,int &i){
        set<string>ans;
        if(s[i] != '{'){
            ans.insert(string(1,s[i]));
            i++;
        }
        else{
            i++;
            ans = solve(s,i);
            i++;
        }
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string>temp = solve(expression,i);
        vector<string>ans(temp.begin(),temp.end());
        return ans;
    }
};