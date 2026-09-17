class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>pref(n+1,0);
        for(int i = 0;i<n;i++){
            pref[i+1] = pref[i]+arr[i];
        }
        int l = 0;
        int r = 0;
        vector<int>len(n,INT_MAX);
        int bsf = INT_MAX;
        int ans = INT_MAX;
        while(r<n){
            int curr = pref[r+1]-pref[l];
            while(curr>target && l<=r){
                l++;
                curr = pref[r+1]-pref[l];
            }
            if(curr == target){
                int curr_len = r-l+1;
                if(l>0 && len[l-1]!=INT_MAX){
                    ans = min(ans,curr_len+len[l-1]);
                }
                bsf = min(bsf,curr_len);
            }
            len[r] = bsf;
            r++;
        }
        return ans == INT_MAX? -1:ans;
    }
};