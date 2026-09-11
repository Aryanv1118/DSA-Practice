class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(auto &x:digits){
            mp[x]++;
        }
        for(int i = 100;i<=998;i+=2){
            int u = i%10;
            int h = i/100;
            int t = (i/10)%10;
            unordered_map<int,int>temp = mp;
            temp[u]--;
            temp[h]--;
            temp[t]--;
            if(temp[u]>=0 && temp[t]>=0 && temp[h]>=0){
                ans++;
            }
        }
        return ans;
    }
};