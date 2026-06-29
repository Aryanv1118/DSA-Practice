class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
       int ans = 0;
       for(int i = 0;i<patterns.size();i++){
        int n = patterns[i].length();
        string s = patterns[i];
        for(int j = 0;j+n<=word.size();j++){
            bool match = true;
            for(int k = j;k<j+n;k++){
                if(s[k-j]!=word[k]){
                    match = false;
                    break;
                }
            }
            if(match){
                ans++;
                break;
            }
        }
       }
       return ans;
    }
};