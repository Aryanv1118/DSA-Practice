class Solution {
public:
    bool detectCapitalUse(string word) {
        int uc = 0;
        for(char c:word){
            if(isupper(c)){
                uc++;
            }
        }
        return uc == word.length() || uc == 0 || (uc == 1 && isupper(word[0]));    
    }
};