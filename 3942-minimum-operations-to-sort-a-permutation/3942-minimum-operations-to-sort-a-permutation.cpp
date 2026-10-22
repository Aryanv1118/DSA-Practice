class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        bool dec = true;
        for(int i = 0;i<n;i++){
            if(nums[(i+1)%n]!=(nums[i]+1)%n)inc = false;
            if(nums[(i+1)%n]!=(nums[i]-1+n)%n)dec = false;
        }
        if(!inc && !dec){
            return -1;
        }
        int ans = INT_MAX;
        if(inc){
            int zidx = find(nums.begin(),nums.end(),0)-nums.begin();
            ans = min(ans,min(zidx,(n-zidx)%n+2));
        }
        if(dec){
            int zidx = find(nums.begin(),nums.end(),0)-nums.begin();
            ans = min(ans,min(zidx+2,1+(n-1-zidx)%n));
        }
        return ans;
    }
};