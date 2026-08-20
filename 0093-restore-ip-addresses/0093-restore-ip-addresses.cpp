class Solution {
public:
    vector<string>ans;
    void backtrack(string s,int idx,string temp,int dots){
        if(dots == 4){
            if(idx == s.length()){
                temp.pop_back();
                ans.push_back(temp);
            }
        }
        for(int i = 1;i<=3;i++){
            if(idx+i>s.length())
                break;
            string segment = s.substr(idx,i);
            if(i>1 && segment[0] == '0')
                break;
            if(stoi(segment) > 255)
                break;
            backtrack(s,idx+i,temp+segment+".",dots+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length()<4 || s.length()>12)
            return {};
        backtrack(s,0,"",0);
        return ans;
    }
};