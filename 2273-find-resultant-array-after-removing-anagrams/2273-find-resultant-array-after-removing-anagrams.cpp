class Solution {
public:
    bool isAnagram(string s1,string s2){
        unordered_map<char,int> mp;
        if(s1.length()!=s2.length())
            return false;
        for(char c:s1)
            mp[c]++;
        for(char c:s2)
            mp[c]--;
        for(auto &it:mp){
            if(it.second != 0)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int i = 0;
        int n = words.size();
        if(n == 1)
            return words;
        vector<string> ans;
        while(i<n){
            if(ans.size()!=0 && isAnagram(words[i],ans.back())){
                i++;
                continue;
            }
            ans.push_back(words[i]);
            i++;
        }
        return ans;
    }
};