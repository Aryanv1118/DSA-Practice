class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>set;
        for(auto &num:nums){
            set.insert(num);
        }
        int ans = (n+1)*k;
        for(int i = 1;i<=n;i++){
            if(!set.count(i*k)){
                ans = i*k;
                break;
            }
        }
        return ans;
    }
};