class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        int ans = 0;
        unordered_set<char>vowels = {'a','e','i','o','u'};
        for(int i = 0;i<n;i++){
            int l = i;
            int r = i;
            if(!vowels.count(word[l]))continue;
            unordered_map<char,bool>used;
            int total = 0;
            while(vowels.count(word[r])){
                if(!used[word[r]]){
                    used[word[r]] = true;
                    total++;
                }
                if(total == 5)ans++;
                r++;
            }
        }
        return ans;
    }
};