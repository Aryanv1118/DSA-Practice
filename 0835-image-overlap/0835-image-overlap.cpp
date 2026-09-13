class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>i1;
        vector<pair<int,int>>i2;
        map<pair<int,int>,int>mp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(img1[i][j] == 1)
                    i1.push_back({i,j});
                if(img2[i][j] == 1)
                    i2.push_back({i,j});
            }
        }
        int n1 = i1.size();
        int n2 = i2.size();
        int i = 0;
        int j = 0;
        for (auto& p1 : i1) {
            for (auto& p2 : i2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                mp[{dx, dy}]++;
            }
        }
        int mx =0;
        for(auto &it:mp){
            mx = max(mx,it.second);
        }
        return mx;
    }
};