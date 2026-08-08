class Solution {
public:
    vector<int> memo;
    bool dfs(string &s,int idx,unordered_set<string>&dict){
        if(idx == s.length())
            return true;
        if(memo[idx]!=-1)
            return memo[idx];
        for(int i = idx;i<s.length();i++){
            string word = s.substr(idx,i-idx+1);
            if(dict.count(word)){
                if(dfs(s,i+1,dict))
                    return memo[idx] = 1;
            }   
        }
        return memo[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        int n = s.length();
        memo.assign(n,-1);
        return dfs(s,0,dict);
    }
};