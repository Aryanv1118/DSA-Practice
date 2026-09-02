class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        if(m<=2)return m;
        int mx = 0;
        for(int i = 0;i<m-1;i++){
            unordered_map<string,int>mp;
            int lc_mx = 0;
            for(int j = i+1;j<m;j++){
               int dx = points[j][0]-points[i][0];
               int dy = points[j][1]-points[i][1];

               int g = gcd(dx,dy);
               dx /= g;
               dy /= g;
               if(dx<0 || (dx == 0 && dy<0)){
                    dx = -dx;
                    dy = -dy;
               }
               string key = to_string(dy)+"/"+to_string(dx);
               mp[key]++;
               lc_mx = max(lc_mx,mp[key]);
            }
            mx = max(lc_mx+1,mx);
        }
        return mx;
    }
};