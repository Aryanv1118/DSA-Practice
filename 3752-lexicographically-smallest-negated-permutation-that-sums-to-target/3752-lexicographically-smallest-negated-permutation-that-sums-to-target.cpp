class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long total_sum = 1LL*n*(n+1)/2;
        if(total_sum<abs(target)){
            return {};
        }
        vector<int>ans(n,0);
        for(int i = 1;i<=n;i++){
            ans[i-1] = i;
        }
        long long rem = total_sum-target;
        if(rem%2!=0)
            return {};
        for(int i = n-1;i>=0;i--){
            if(ans[i]>rem/2)continue;
            rem -= 2LL*ans[i];
            ans[i] *= -1;
            if(rem == 0)break;
        }
        sort(ans.begin(),ans.end());
        return ans; 
    }
};