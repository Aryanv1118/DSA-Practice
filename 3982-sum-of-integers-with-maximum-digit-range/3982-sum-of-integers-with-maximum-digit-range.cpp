class Solution {
public:
    int digitRange(int x){
        int mind = INT_MAX;
        int maxd = INT_MIN;
        if(x == 0)
            return maxd - mind;
        while(x>0){
            int digit = x % 10;
            maxd = max(maxd,digit);
            mind = min(mind,digit);
            x = x/10;
        }
        return maxd-mind;
    }
    int maxDigitRange(vector<int>& nums) {
        int mdr = -1;
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            mdr = max(mdr,digitRange(nums[i]));
        }
        for(int i = 0;i<n;i++){
            if(digitRange(nums[i]) == mdr)
                ans += nums[i];
        }
        return ans;
    }
};