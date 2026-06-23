class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        if(restrictions.back()[0]!=n){
            restrictions.push_back({n,n-1});
        }
        int nr = restrictions.size();
        for(int i = 1;i<nr;i++){
            restrictions[i][1] = min(restrictions[i][1],(restrictions[i][0]-restrictions[i-1][0])+restrictions[i-1][1]);
        }
        for(int i = nr-2;i>=0;i--){
            restrictions[i][1] = min(restrictions[i][1],(restrictions[i+1][0]-restrictions[i][0])+restrictions[i+1][1]);
        }
        int ans = 0;
        for(int i = 0;i<nr-1;i++){
            int height = ((restrictions[i+1][0]-restrictions[i][0])+restrictions[i][1]+restrictions[i+1][1])/2;
            ans = max(ans,height);
        }
        return ans;
    }
};