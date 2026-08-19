class Solution {
public:
    using uo = unordered_map<char,int>;
    bool check(uo &smp,uo &tmp){
        for(auto &it:tmp){
            if(it.second > smp[it.first]){
                return false;
            }
        }
        return true;
    }   
    string minWindow(string s, string t) {
        unordered_map<char,int>tmp;
        unordered_map<char,int>smp;
        for(char c:t){
            tmp[c]++;
        }
        int l = 0;
        int r = 0;
        int n = s.length();
        int len = INT_MAX;
        int left = 0;
        int right = 0;
        string ans;
        while(r<n){
            smp[s[r]]++;
            r++;
            while(check(smp,tmp) && r-l >= t.size()){
                if(r-l<len){
                    left = l;
                    right = r;
                    len = right-left;
                }
                smp[s[l]]--;
                l++;
            }   
        }
        ans = s.substr(left,right-left);
        return ans;
    }
};