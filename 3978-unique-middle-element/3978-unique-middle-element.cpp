class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        int midelement = nums[mid];
        int count = 0;
        for(auto x:nums){
            if(x == midelement)
                count++;
        }
        if(count>1)
            return false;
        return true;
    }
};