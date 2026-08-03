class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memo.assign(n,INT_MIN);
        int adv = dfs(stoneValue,0,n);
        return adv > 0 ? "Alice" : (adv == 0 ? "Tie":"Bob") ;
    }
private:
    vector<int> memo;
    int dfs(vector<int>& nums,int i,int n){
        if(i >= n){
            return 0;
        }
        if(memo[i]!=INT_MIN){
            return memo[i];
        }
        int sum = 0;
        int ans = INT_MIN;
        for(int k = 1;k<=3 && i+k-1<n;k++){
            sum += nums[i+k-1];
            ans = max(ans,sum-dfs(nums,i+k,n));
        }
        memo[i] = ans; 
        return ans;
    }
};