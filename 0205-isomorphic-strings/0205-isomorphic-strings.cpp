class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_set<char> set;
        int ns = s.size();
        int nt = t.size();
        if(nt!=ns){
            return false;
        }
        for(int i = 0;i<nt;i++){
            if(!mp.count(s[i]) && !set.count(t[i])){
                mp[s[i]] = t[i];
                set.insert(t[i]);
            }
            if(!mp.count(s[i]) && set.count(t[i])){
                return false;
            }
            if(mp.count(s[i]) && mp[s[i]]!=t[i]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;
    }
};