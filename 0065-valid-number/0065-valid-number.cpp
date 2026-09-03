class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        bool exp = false;
        bool dot = false;
        bool sign = false;
        bool nseen = false;
        for(int i = 0;i<n;i++){
            if(s[i] >= '0' && s[i] <= '9')
                nseen = true;
            else if(s[i] == '-' || s[i] == '+'){
                if(!(i==0 || (i > 0 && (s[i-1] == 'e'|| s[i-1] == 'E'))))
                    return false;
                else
                    sign = true;
            }
            else if(s[i] == '.'){
                if(dot || exp)
                    return false;
                else
                    dot = true;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(exp || !nseen)
                    return false;
                else{
                    exp = true;
                    nseen = false;
                }
            }
            else{
                return false;
            }
            if(i == n-1){
                if(s[i] >= '0' && s[i]<= '9' || (s[i] == '.' && nseen))
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};