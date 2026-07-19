class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs){ 
        vector<bool> ans;
        vector<int> source;
        int n = s.length();
        for(int i = 0;i<s.length();i++){
            if(s[i] == '0')
                source.push_back(i);
        }
        for(string t:strs){
            bool match = true;
            int freq0 = 0;
            int freq1 = 0;
            int q_count = 0;
            for(int j = 0;j<t.length();j++){
                if(t[j] == '0')
                    freq0++;
                else if(t[j] == '?')
                    q_count++;
                else
                    freq1++;
            }
            int needOne = (n - source.size()) - freq1;
            int needZero = source.size() - freq0;
            if (needZero < 0 || needOne < 0 || needZero + needOne != q_count) {
                ans.push_back(false);
                continue;
            }
            int ptr = 0;
            for (int i = 0; i < n; i++) {
                if (t[i] == '0') {
                    if (ptr >= source.size() || source[ptr] < i) {
                        match = false;
                        break;
                    }
                    ptr++;
                }
                else if (t[i] == '?' && needZero > 0) {
                    if (ptr >= source.size() || source[ptr] < i) {
                        match = false;
                        break;
                    }
                    needZero--;
                    ptr++;
                }
            }
            ans.push_back(match);
        }
        return ans; 
    }
};