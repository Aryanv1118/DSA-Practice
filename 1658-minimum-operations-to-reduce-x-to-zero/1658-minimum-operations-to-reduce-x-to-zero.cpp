class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int p:nums){
            sum += p;
        }
        vector<int>pref(n+1,0);
        for(int i = 0;i<n;i++){
            pref[i+1] = pref[i]+nums[i]; 
        }
        int sm = sum-x;
        int len = -1;
        int l = 0;
        for(int i = 0;i<n;i++){
            if((pref[i+1]-pref[l])>sm){
                while(l<=i && ((pref[i+1]-pref[l])>sm)){
                    l++;
                }
            }
            if((pref[i+1]-pref[l]) == sm){
                len = max(len,i-l+1);
            }
        }
        return len == -1?-1:n-len;
    }
};