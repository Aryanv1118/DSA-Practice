class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int l = 0;
        int r = 0;
        int n = s.length();
        while(r<n){
            if(s[r]!=' '){
                r++;
            }
            else{
                reverse(s.begin()+l,s.begin()+r);
                l = r+1;
                r++;
            }
        }
        reverse(s.begin()+l,s.begin()+r);
        int i = 0;
        while(i+1<s.length()){
            while(s[i] == ' ' && s[i+1] == ' ')
                s.erase(i,1);
            i++;
        }
        int a = 0;
        int b = s.length()-1;
        while(a <= b &&s[a] == ' ')a++;
        while(b >= a && s[b] == ' ')b--;
        s = s.substr(a,b-a+1);
        return s;
    }
};