class Solution {
public:
    bool pcheck(int mo,vector<int>&nums,int parity){
        for(int &a:nums){
            if((a&1) != parity && a<=mo)
                return false;
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        int mo = INT_MAX;
        for(auto &x:nums1){
            if(x&1)
                mo = min(mo,x);
        }
        return pcheck(mo,nums1,0) || pcheck(mo,nums1,1);
    }
};