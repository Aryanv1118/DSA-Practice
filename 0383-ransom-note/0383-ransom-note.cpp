class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        int m = magazine.size();
        int n = ransomNote.size();
        if(n>m){
            return false;
        }
        for(int i = 0;i<m;i++){
            mp[magazine[i]]++;
        }
        for(int i=0;i<n;i++){
            mp[ransomNote[i]]--;
        }
        for(auto &it:mp){
            if(it.second<0){
                return false;
            }
        }
        return true;
    }
};