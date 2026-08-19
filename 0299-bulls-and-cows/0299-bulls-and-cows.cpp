class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int n = secret.size();
        unordered_map<char,int>mp;
        vector<bool>vis(n,false);
        int cow = 0;
        for(int i = 0;i<n;i++){
            if(secret[i] == guess[i]){
                vis[i] = true;
                bull++;
            }
            else{
                mp[secret[i]]++;
            }
        }
        for(int i = 0;i<n;i++){
            if(!vis[i] && mp[guess[i]]>0){
                mp[guess[i]]--;
                cow++;
            }
        }
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};