class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        int n = s.length();
        for(char c:s){
            if(c == '1')
                ones++;
        }
        int l = 0;
        int r = n-1;
        while(l<n && s[l] == '1')
            l++;
        while(r>=0 && s[r] == '1')
            r--;
        if(l>r)
            return ones;
        int len = 1;
        vector<pair<int,char>> block;
        for(int i = l+1;i<=r;i++){
            if(s[i] == s[i-1]){
                len++;
            }
            else{
                block.push_back({len,s[i-1]});
                len = 1;
            }
        }
        block.push_back({len,s[r]});
        int gain = 0;
        for(int i = 0;i+2<block.size();i+=2){
            gain = max(gain,block[i].first+block[i+2].first);
        }
        return ones+gain;
    }
};