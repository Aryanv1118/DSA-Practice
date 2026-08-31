class Solution {
public:
    bool check(string &s){
        for(int i = 0;i<s.length();i++){
            if(!((s[i] <= 57 && s[i] >= 48) || s[i] == 95 || (s[i]>= 65 && s[i]<= 90) || (s[i] <= 122 && s[i] >= 97))){
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int>mp = {{"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}};
        vector<pair<string,string>>pr;
        vector<string>ans;
        for(int i = 0;i<code.size();i++){
            if(!code[i].empty() && check(code[i]) && mp.count(businessLine[i]) && isActive[i]){
                pr.push_back({businessLine[i],code[i]});
            }
        }
        sort(pr.begin(),pr.end(),[&](const pair<string,string>&a,pair<string,string>&b){
            if(mp[a.first]!=mp[b.first]){
                return mp[a.first]<mp[b.first];
            }
            return a.second < b.second;
        });
        for(int i = 0;i<pr.size();i++){
            ans.push_back(pr[i].second);
        }
        return ans;
    }
};