class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string t = s;
        int i = 0;
        int j = s.length();
        while(i<j){
            while(i<j && t[i]!=x)
                i++;
            while(i<j && t[j]!=y)
                j--;
            if(i<j){
                swap(t[i],t[j]);
                i++;
                j--;
            }
        }
        return t;   
    }
};