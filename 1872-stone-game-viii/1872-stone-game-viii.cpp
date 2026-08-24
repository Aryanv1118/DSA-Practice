class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>prefix(n+1);
        for(int i = 0;i<n;i++){
            prefix[i+1] = prefix[i]+stones[i];
        }
        int ans = prefix[n];
        for(int i = n-1;i>1;i--){
            ans = max(ans,prefix[i]-ans);
        }
        return ans;
    }
};