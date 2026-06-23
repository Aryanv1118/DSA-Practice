class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> mp (26,0);
        int num = INT_MAX;
        for(char c:text){
            mp[c-'a']++;
        }
        vector<int> balloon = {0,1,11,13,14};
        for(int a:balloon){
            if(a == 11 || a == 14){
                num = min(num,mp[a]/2);
                continue;
            }
            num = min(num,mp[a]);
        }
        return num;
    }
};