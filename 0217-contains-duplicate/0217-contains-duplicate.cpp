class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> s;
        for(auto it:nums){
            s[it]++;
        } 
        for(auto z:s){
            if(z.second>1){
                return true;
            }
        }
        return false;      
    }
};