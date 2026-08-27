class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int>freq(26,0);
        string ans = "";
        for(auto& c:s){
            freq[c-'a']++;
        }
        int idx = 0;
        while(idx<target.size() && freq[target[idx]-'a']>0){
            freq[target[idx]-'a']--;
            idx++;
        }
        if (idx < target.size()) {
            bool possible = false;
            char c;
            for (int i = target[idx] - 'a' + 1; i < 26; i++) {
                if (freq[i] > 0) {
                    possible = true;
                    c = i + 'a';
                    freq[i]--;
                    break;
                }
            }
            ans = target.substr(0, idx);
            if (possible) {
                ans.push_back(c);
                for (int i = 0; i < 26; i++) {
                    ans.append(freq[i], i + 'a');
                }
                return ans; 
            }
                       
        }
        for(int j = idx-1;j>=0;j--){
            freq[target[j]-'a']++;
            for(int i = target[j]-'a'+1;i<26;i++){
                if(freq[i] > 0){
                    ans = target.substr(0,j);
                    ans.push_back(i+'a');
                    freq[i]--;
                    for(int k = 0;k<26;k++){
                        ans.append(freq[k],k+'a');
                    }
                    return ans;
                }
            }
        }
        return "";
    }
};