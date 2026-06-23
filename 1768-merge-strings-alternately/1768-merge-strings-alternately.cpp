class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        int k = 0;
        string s;
        int nw1 = word1.size();
        int nw2 = word2.size();
        while(i<nw1 || j<nw2){
            if(i<nw1 && j<nw2){
                s.push_back(word1[i++]);
                s.push_back(word2[j++]);
            }
            if(i == nw1 && j<nw2){
                s.push_back(word2[j++]);
            }
            if(j == nw2 && i<nw1){
                s.push_back(word1[i++]);
            }
        }
        return s;
    }
};