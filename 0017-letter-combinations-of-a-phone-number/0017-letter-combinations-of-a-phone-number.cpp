class Solution {
public:
    using uo = unordered_map<char,string>;
    void backtrack(string s,uo &mp,vector<string>&ans,string digits,int i){
        if(i == digits.size()){
            ans.push_back(s);
            return;
        }
        for(int j = 0;j<mp[digits[i]].length();j++){
            s.push_back(mp[digits[i]][j]);
            backtrack(s,mp,ans,digits,i+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       unordered_map<char,string>mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
       string s;
       vector<string> ans;
       backtrack(s,mp,ans,digits,0);
       return ans; 
    }
};