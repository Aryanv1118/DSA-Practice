class Solution {
public:
    vector<vector<int>>memo;
    vector<int>suffix;
    int dfs(int idx,vector<int>& nums,int m){
        if(idx == nums.size())
            return 0;
        if(idx + 2*m >= nums.size())
            return suffix[idx];
        if(memo[idx][m]!=-1)
            return memo[idx][m];
        int ans = 0;
        for(int i = 1;i<=2*m;i++){
            int opponent = dfs(idx + i,nums,max(i,m));
            int current = suffix[idx] - opponent;
            ans = max(ans,current);
        }
        return memo[idx][m] = ans;
    } 
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        suffix.assign(n+1,0);
        for(int i = n-1;i>=0;i--){
            suffix[i] = suffix[i+1] + piles[i];
        }
        memo.assign(n,vector<int>(n+1,-1));
        return dfs(0,piles,1);
    }
};