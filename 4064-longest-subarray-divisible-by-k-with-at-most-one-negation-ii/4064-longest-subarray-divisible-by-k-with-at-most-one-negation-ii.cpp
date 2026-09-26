class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n+1,0);
        for(int i = 0;i<n;i++){
            pref[i+1] = (pref[i]+nums[i])%k;
            if(pref[i+1]<0)
                pref[i+1] = (pref[i+1]+k)%k;
        }
        vector<int>first(k,INT_MAX);
        for(int i = 0;i<=n;i++){
            if(first[pref[i]]==INT_MAX){
                first[pref[i]] = i;
            }
        }
        vector<int>order;
        for(int i = 0;i<k;i++){
            if(first[i]!=INT_MAX)
                order.push_back(i);
        }
        sort(order.begin(),order.end(),[&](int a,int b){
            return first[a]<first[b];
        });
        vector<int>best(k,INT_MAX);
        vector<int>p(k,0);
        int ans = 0;
        for(int i = 0;i<=n;i++){
            ans = max(ans,i-first[pref[i]]);
        }
        for(int i = 0;i<n;i++){
            int rem = (2LL*nums[i])%k;
            if(rem<0)
                rem += k;
            while(p[rem]<(int)order.size() && first[order[p[rem]]]<= i){
                int q = order[p[rem]];
                int need = (q+rem)%k;
                best[need] = min(best[need],first[q]);
                p[rem]++;
            }
            int r = pref[i+1];
            if(best[r]!=INT_MAX){
                ans = max(ans,i+1-best[r]);
            }
        }
        return ans;
    }
};